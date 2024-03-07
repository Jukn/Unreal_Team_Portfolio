// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InventoryUI/BTS_InventoryComponent.h"
#include "UI/InventoryUI/Tile.h"
#include "Kismet/KismetArrayLibrary.h"
#include"UI\ItemUI\BTS_ItemObject.h"

// Sets default values for this component's properties
UBTS_InventoryComponent::UBTS_InventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

TMap<UBTS_ItemObject*, FTile> UBTS_InventoryComponent::GetAllItems()
{
	TMap<UBTS_ItemObject*, FTile> AllItems;

	int32 index = 0;
	for (auto& LocalItem : Items)
	{
		if (LocalItem)
		{
			if (!AllItems.Contains(LocalItem))
				AllItems.Add(LocalItem, IndexToTile(index));
		}
		++index;
	}
	return AllItems;
}

FTile UBTS_InventoryComponent::IndexToTile(int32 Index) const
{
	FTile Tile;

	Tile.X = Index % Colums;
	Tile.Y = Index / Colums;

	return Tile;
}

int32 UBTS_InventoryComponent::TileToIndex(FTile Tile) const
{
	int32 Index = Tile.Y * Colums + Tile.X;
	return Index;
}

void UBTS_InventoryComponent::RemoveItem(UBTS_ItemObject* ItemObject)
{
	int32 index = 0;

	if (ItemObject)
	{
		for (auto& item : Items)
		{
			if (item == ItemObject)
			{
				if (index >= Items.Num())
				{
					Items.SetNum(index + 1);
				}
				Items[index] = nullptr;

				IsDirty = true;
			}
			++index;
		}
	}
}

bool UBTS_InventoryComponent::IsRoomAvailable(UBTS_ItemObject* ItemObject, int32 TopLeftIndex)
{

	FTile Tile = IndexToTile(TopLeftIndex);
	FIntPoint Demensions = ItemObject->GetDimensions();
	int32 LastIndexX = Demensions.X - 1 + Tile.X;
	int32 LastIndexY = Demensions.Y - 1 + Tile.Y;

	for (int32 i = Tile.X; i <= LastIndexX; ++i)
	{
		for (int32 j = Tile.Y; j <= LastIndexY; ++j)
		{
			if (i >= 0 && j >= 0 && i < Colums && j < Rows)
			{

				FTile TileIndex;
				TileIndex.X = i;
				TileIndex.Y = j;
				FItemIndex Data = GetItemIndex(TileToIndex(TileIndex));
				if (Data.Vaild)
				{
					if (IsValid(Data.ItemObject))
					{
						return false;
					}
				}
				else
				{
					return false;
				}

			}
			else
			{
				return false;
			}

		}

	}

	return true;
}

void UBTS_InventoryComponent::AddItemAt(UBTS_ItemObject* ItemObject, int32 TopLeftIndex)
{
	FTile Tile = IndexToTile(TopLeftIndex);
	FIntPoint Demensions = ItemObject->GetDimensions();
	int32 LastIndexX = Demensions.X - 1 + Tile.X;
	int32 LastIndexY = Demensions.Y - 1 + Tile.Y;

	for (int32 i = Tile.X; i <= LastIndexX; ++i)
	{
		for (int32 j = Tile.Y; j <= LastIndexY; ++j)
		{
			FTile TileIndex;
			TileIndex.X = i;
			TileIndex.Y = j;
			//Todo ���Ŀ� ������ �� Ȯ��
			if (TileToIndex(Tile) >= Items.Num())
			{
				Items.SetNum(TileToIndex(Tile) + 1);
			}
			Items[TileToIndex(TileIndex)] = ItemObject;

		}
	}
	IsDirty = true;
}

bool UBTS_InventoryComponent::TryAddItem(UBTS_ItemObject* ItemObject)
{
	if (!IsValid(ItemObject))
	{
		ItemObject->Rotate();
		return false;
	}

	int32 TopLeftIndex = 0;

	for (auto& item : Items)
	{
		if (IsRoomAvailable(ItemObject, TopLeftIndex))
		{
			AddItemAt(ItemObject, TopLeftIndex);
			break;
		}
		TopLeftIndex++;
	}

	if (IsOnce)
	{
		IsOnce = false;
		TopLeftIndex = 0;

		ItemObject->Rotate();

		for (auto& item : Items)
		{
			if (IsRoomAvailable(ItemObject, TopLeftIndex))
			{
				AddItemAt(ItemObject, TopLeftIndex);
				break;
			}
			TopLeftIndex++;
		}
	}

	return true;
}

FItemIndex UBTS_InventoryComponent::GetItemIndex(int32 TopLeftIndex)
{
	FItemIndex ret;
	if (Items.IsValidIndex(TopLeftIndex))
	{
		ret.Vaild = true;
		ret.ItemObject = Items[TopLeftIndex];
		return ret;

	}
	ret.Vaild = false;
	ret.ItemObject = nullptr;
	return ret;
}


// Called when the game starts
void UBTS_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UBTS_InventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


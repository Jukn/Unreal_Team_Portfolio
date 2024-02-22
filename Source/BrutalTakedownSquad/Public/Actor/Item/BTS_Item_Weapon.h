// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Item/BTS_Item.h"
#include "BTS_Item_Weapon.generated.h"

// Weapon Base Class
// Admin: KSW
UCLASS()
class BRUTALTAKEDOWNSQUAD_API ABTS_Item_Weapon : public ABTS_Item
{
	GENERATED_BODY()

public:
	ABTS_Item_Weapon();

	virtual void Tick(float DeltaTime) override;

	virtual void OnPickUpOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UBTS_GameplayAbility> PrimaryAbilityClass; // �÷��̾�� ���޵Ǵ� ������ �⺻ ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UBTS_GameplayAbility> SecondaryAbilityClass; //  �÷��̾�� ���޵Ǵ� ADS �ɷ�

};

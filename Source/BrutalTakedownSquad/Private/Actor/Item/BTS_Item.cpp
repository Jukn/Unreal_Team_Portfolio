
#include "Actor/Item/BTS_Item.h"

ABTS_Item::ABTS_Item()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	ItemName = FName("Default Item Name");

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetSphereRadius(100.f);
	SphereCollider->SetupAttachment(RootComponent);
	
	// �浹ó��
	SphereCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereCollider->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereCollider->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereCollider->SetGenerateOverlapEvents(true);
	SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &ABTS_Item::OnPickUp);

	StaticMesh->SetupAttachment(SphereCollider);
	
	// �浹ó��
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMesh->SetGenerateOverlapEvents(false);
}

void ABTS_Item::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABTS_Item::OnPickUp(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ItemOwnerCharacterBase = CastChecked<ABTS_CharacterBase>(OtherActor);
	if(!ItemOwnerCharacterBase || !ItemOwnerCharacterBase->HasAuthority()) return;

	ItemOwnerCharacterBase->GetAbilitySystemComponent()->GiveAbility(FGameplayAbilitySpec(SharedItemAbilityClass));
}

void ABTS_Item::OnDrop()
{
	// TODO: �������� ���� �� �����Ƽ ����
	ItemOwnerCharacterBase = nullptr;
}

//UMeshComponent* ABTS_Item::GetMesh()
//{
//	return StaticMesh;
//}

FName ABTS_Item::GetItemName()
{
	return ItemName;
}


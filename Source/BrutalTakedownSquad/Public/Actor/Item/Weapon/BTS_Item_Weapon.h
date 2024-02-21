// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actor/Item/BTS_Item.h"
#include "Abilities/GameplayAbility.h"
#include "BTS_Item_Weapon.generated.h"

// Weapon Base Class
// Admin: KSW
UCLASS()
class BRUTALTAKEDOWNSQUAD_API ABTS_Item_Weapon : public ABTS_Item
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UGameplayAbility> PrimaryAbilityClass; // �÷��̾�� ���޵Ǵ� ������ �⺻ ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<UGameplayAbility> SecondaryAbilityClass; //  �÷��̾�� ���޵Ǵ� ADS �ɷ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TObjectPtr<UAnimMontage> FireMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	TObjectPtr<USoundBase> FireSound;

	ABTS_Item_Weapon();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	void OnPickUpOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
};

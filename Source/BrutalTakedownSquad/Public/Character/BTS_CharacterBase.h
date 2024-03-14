
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interface/CombatInterface.h"
#include "Interface/AnimationEnumInterface.h"

#include "BTS_CharacterBase.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;
class UGameplayAbility;
class UBTS_AbilitySystemComponent;
class UBTS_WeaponComponent;
class UBTS_ArmorComponent;
class UBTS_InventoryComponent;

struct FGameplayTag;

// Character base class that uses the AbilitySystemComponent for abilities and attributes
// Admin: YWS
UCLASS()
class BRUTALTAKEDOWNSQUAD_API ABTS_CharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface, public IAnimationEnumInterface
{
	GENERATED_BODY()

public:
	ABTS_CharacterBase();

	// Rule: Always cast to BTS_UAbilitySystemComponent after calling this function
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const;

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	virtual void ActivateAbilityByTag(FGameplayTag AbilityTag) const;

	UFUNCTION(BlueprintCallable, Category = "WeaponComponent")
	UBTS_WeaponComponent* GetWeaponComponent() const;

	// ICombatInterface��(��) ���� ��ӵ�
	virtual void Die() override;

	virtual UAnimMontage* GetHitReactMontage_Implementation() override;

	// IAnimationEnumInterface��(��) ���� ��ӵ�

	// Setter
	virtual void SetIsSprint_Implementation(bool bNewSprint) override { bIsSprint = bNewSprint; }

	virtual void SetIsAimable_Implementation(bool bNewAimable) override { bIsAimable = bNewAimable; }

	virtual void SetTurnRate_Implementation(float NewTurnRate) override {};

	virtual void SetAnimationState_Implementation(EAnimationState NewState) override {}

	virtual void SetOnLandState_Implementation(EOnLandState NewState) override {}

	// Getter
	virtual bool GetIsSprint_Implementation() const override { return bIsSprint; }

	virtual bool GetIsAimable_Implementation() const override { return bIsAimable; }

	virtual float GetTurnRate_Implementation() override { return 0; };

	virtual EAnimationState GetAnimationState_Implementation() override { return EAnimationState::None; }

	virtual EOnLandState GetOnLandState_Implementation() override { return EOnLandState::None; }

protected:

	// AbilitySystemComponent and AttributeSet

	UPROPERTY()
	TObjectPtr<UBTS_AbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultAttribute;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> VitalAttribute;

protected:
	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo();

	void InitializeDefaultAttributes() const;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass) const;

	void AddCharacterAbilities() const;

private:
	UPROPERTY(EditAnywhere, Category = "Abilities")	
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;	// change to Basic Ability

	UPROPERTY(EditAnywhere, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> PassiveAbilities;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<UAnimMontage> HitReactMontage;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBTS_WeaponComponent> WeaponComponent;


	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBTS_ArmorComponent> ArmorComponent;


	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBTS_InventoryComponent> InventoryComponent;

	bool bIsSprint = false;

	bool bIsAimable = false;
};

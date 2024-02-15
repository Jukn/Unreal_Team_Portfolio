// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/BTSPlayerState.h"

#include "AbilitySystem/BTSAbilitySystemComponent.h"
#include "AbilitySystem/BTSAttributeSet.h"
#include "Net/UnrealNetwork.h"

ABTSPlayerState::ABTSPlayerState()
{
	NetUpdateFrequency = 100.f; // ������ Ŭ���̾�Ʈ ������Ʈ�� �õ��ϴ� ��.

	AbilitySystemComponent = CreateDefaultSubobject<UBTSAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UBTSAttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ABTSPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ABTSPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

void ABTSPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

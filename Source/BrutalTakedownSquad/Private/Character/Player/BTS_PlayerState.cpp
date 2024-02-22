
#include "Character/Player/BTS_PlayerState.h"

#include "AbilitySystem/BTS_AbilitySystemComponent.h"
#include "AbilitySystem/BTS_AttributeSet.h"
#include "Net/UnrealNetwork.h"

ABTS_PlayerState::ABTS_PlayerState()
{
	NetUpdateFrequency = 100.f; // ������ Ŭ���̾�Ʈ ������Ʈ�� �õ��ϴ� ��.

	AbilitySystemComponent = CreateDefaultSubobject<UBTS_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UBTS_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* ABTS_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ABTS_PlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

void ABTS_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}

// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/BTSAttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GameplayEffectExtension.h"

UBTSAttributeSet::UBTSAttributeSet()
{
}

void UBTSAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBTSAttributeSet, Health, OldHealth);
}

void UBTSAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBTSAttributeSet, MaxHealth, OldMaxHealth);
}

void UBTSAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBTSAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBTSAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UBTSAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// Modifier�� �����Ͽ� ��ȯ�� ���� ����
	if (Attribute == GetHealthAttribute())
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
}

void UBTSAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	//SetEffectProperties(Props, Data);

	// effect�� ����� �������� ����
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}

}

void UBTSAttributeSet::SetEffectProperties(FEffectProperties& Props, const FGameplayEffectModCallbackData& Data) const
{
	// not yet
}

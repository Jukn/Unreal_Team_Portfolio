
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/// <summary>
/// AbilitySystemComponent�� ��ӹ޾Ƽ� ����� �߰��� ������Ʈ
/// </summary>
/// <remarks>
/// 
/// </remarks>
/// @author ������
/// @date last change 2024/02/15
struct FBTSGameplayTags
{
public:
	static const FBTSGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attributes_MaxHealth;
	FGameplayTag Attributes_CurrentHealth;

	// Input Tags
	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;

private:
	static FBTSGameplayTags GameplayTags;
};
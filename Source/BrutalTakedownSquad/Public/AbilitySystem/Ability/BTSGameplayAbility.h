
#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "BTSGameplayAbility.generated.h"

/// <summary>
/// ���̽� �����÷��� �����Ƽ Ŭ����
/// </summary>
/// <remarks>
/// 
/// </remarks>
/// @author ������
/// @date last change 2024/02/15
UCLASS()
class BRUTALTAKEDOWNSQUAD_API UBTSGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	FGameplayTag StartupInputTag;
};

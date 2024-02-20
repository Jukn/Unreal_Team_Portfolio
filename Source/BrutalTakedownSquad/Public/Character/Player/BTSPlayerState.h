
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "BTSPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

/// <summary>
/// Player State Class
/// </summary>
/// <remarks>
/// 
/// </remarks>
/// @author ������
/// @date last change 2024/02/15
UCLASS()
class BRUTALTAKEDOWNSQUAD_API ABTSPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABTSPlayerState();

	// IAbilitySystemInterface��(��) ���� ��ӵ�
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UAttributeSet* GetAttributeSet() const;

public:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};

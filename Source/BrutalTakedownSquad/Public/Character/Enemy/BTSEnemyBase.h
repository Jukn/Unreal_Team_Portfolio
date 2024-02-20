// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BTSCharacterBase.h"
#include "BTSEnemyBase.generated.h"


class UBehaviorTree;
class ABTSAIController;

/// <summary>
/// AI Enemy Ŭ����
/// </summary>
/// <remarks>
/// 
/// </remarks>
/// @author ä�غ�
/// @date last change 2024/02/21
UCLASS()
class BRUTALTAKEDOWNSQUAD_API ABTSEnemyBase : public ABTSCharacterBase
{
	GENERATED_BODY()
	
public:
	ABTSEnemyBase();

	virtual void PossessedBy(AController* NewController)override;

	virtual void Tick(float Deltatime)override;
protected:

	virtual void BeginPlay() override;

	virtual void InitAbilityActorInfo() override;


	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UPROPERTY()
	TObjectPtr<ABTSAIController> BTSAIController;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "AI")
	bool Runaway;

	bool DoOnce = false;
};

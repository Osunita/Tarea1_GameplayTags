// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "PokeAttack.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class UPokeAttack : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag AttackType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxUses;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 RemainingUses;
	
	UPokeAttack();
	
	UFUNCTION(BlueprintCallable)
	bool TryUseAttack();
};

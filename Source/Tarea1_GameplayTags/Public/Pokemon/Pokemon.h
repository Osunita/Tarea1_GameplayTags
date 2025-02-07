// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Object.h"
#include "Pokemon.generated.h"

class UPokeAttack;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FTypeEffectiveness : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer StrongAgainst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer WeakAgainst;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer ImmuneTo;
};


UCLASS()
class TAREA1_GAMEPLAYTAGS_API UPokemon : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer PokemonTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UPokeAttack*> Attacks;

	UFUNCTION(BlueprintCallable)
	bool AddAttack(UPokeAttack* NewAttack);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* TypeEffectivenessTable;
	
	UFUNCTION(BlueprintCallable)
	virtual void Attack(UPokemon* Target, UPokeAttack* AttackToUse);

private:
	float CalculateDamage(const UPokeAttack* Attack, const FGameplayTagContainer& TargetTypes);
};
// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon/Pokemon.h"
#include "Pokemon/PokeAttack.h"

bool UPokemon::AddAttack(UPokeAttack* NewAttack)
{
	if (Attacks.Num() >= 4)
	{
		UE_LOG(LogTemp, Warning, TEXT("4 attacks max!"));
		return false;
	}

	if (NewAttack)
	{
		Attacks.Add(NewAttack);
		return true;
	}

	UE_LOG(LogTemp, Warning, TEXT("Invalid attack!"));
	return false;
}

void UPokemon::Attack(UPokemon* Target, UPokeAttack* AttackToUse)
{
	if (AttackToUse->TryUseAttack())
	{
		CalculateDamage(AttackToUse, Target->PokemonTypes);
		// Hacer daño al pokemon
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No PP"));
	}
	
}

float UPokemon::CalculateDamage(const UPokeAttack* Attack, const FGameplayTagContainer& TargetTypes)
{
	FTypeEffectiveness* AttackEffectiveness = TypeEffectivenessTable->FindRow<FTypeEffectiveness>(Attack->AttackType.GetTagName(),TEXT("Multiply"));

	float Multiplier = 1.0f;

	// Bucle para todos los tipos del rival
	for (const FGameplayTag& DefendingType : TargetTypes)
	{
		if (AttackEffectiveness->ImmuneTo.HasTagExact(DefendingType))
		{
			return 0.0f;
		}
		
		if (AttackEffectiveness->StrongAgainst.HasTagExact(DefendingType))
		{
			Multiplier *= 2.0f;
		}
		else if (AttackEffectiveness->WeakAgainst.HasTagExact(DefendingType))
		{
			Multiplier *= 0.5f;
		}
	}
	
	float FinalDamage = Attack->BaseDamage * Multiplier;
	return FinalDamage;
}

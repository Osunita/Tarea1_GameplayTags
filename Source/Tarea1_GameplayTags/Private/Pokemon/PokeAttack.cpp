// Fill out your copyright notice in the Description page of Project Settings.


#include "Pokemon/PokeAttack.h"

UPokeAttack::UPokeAttack()
{
	RemainingUses = MaxUses;
}

bool UPokeAttack::TryUseAttack()
{
	if (RemainingUses > 0)
	{
		RemainingUses--;
		return true;
	}
	return false;
}
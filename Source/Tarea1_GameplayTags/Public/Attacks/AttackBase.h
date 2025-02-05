// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AttackBase.generated.h"

/**
 * 
 */
UCLASS()
class TAREA1_GAMEPLAYTAGS_API UAttackBase : public UObject
{
	GENERATED_BODY()

public:
		virtual bool TryAttack(AActor* Attacker);
};

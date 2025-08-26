// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StatusEffect.generated.h"

class AEnemy;

/**
 * 
 */
UCLASS(Blueprintable)
class TOXICREVENANT_API UStatusEffect : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
    float Duration = 5.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
    float DamagePerSecond = 2.0f;

    virtual void Apply(AEnemy* Enemy);
    virtual void Tick(AEnemy* Enemy, float DeltaTime);

protected:
    float TimeElapsed = 0.0f;
};

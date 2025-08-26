// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SampleCurrency.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class TOXICREVENANT_API USampleCurrency : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
    int32 BloodSamples = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Currency")
    int32 CompoundSamples = 0;

    UFUNCTION()
    bool HasEnough(int32 Cost) const;

    UFUNCTION()
    void Deduct(int32 Cost);

    UFUNCTION()
    void Add(int32 Amount);
};

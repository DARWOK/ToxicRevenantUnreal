// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Command.generated.h"

class APlayerCharacter;

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class TOXICREVENANT_API UCommand : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	virtual void Execute(APlayerCharacter* Character) {}
};

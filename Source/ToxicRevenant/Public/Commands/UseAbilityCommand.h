// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Commands/Command.h"
#include "UseAbilityCommand.generated.h"

class APlayerCharacter;

/**
 * 
 */
UCLASS()
class TOXICREVENANT_API UUseAbilityCommand : public UCommand
{
	GENERATED_BODY()
	
public:
	virtual void Execute(APlayerCharacter* Character) override;
};

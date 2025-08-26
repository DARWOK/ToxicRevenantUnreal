// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventorySystem.generated.h"

class IAbilityInterface;

/**
 * 
 */
UCLASS(Blueprintable)
class TOXICREVENANT_API UInventorySystem : public UObject
{
	GENERATED_BODY()
	
public:
    UFUNCTION()
    void AddAbility(TScriptInterface<IAbilityInterface> Ability);

    UFUNCTION()
    TScriptInterface<IAbilityInterface> GetEquippedAbility() const;

    UFUNCTION()
    void EquipAbility(TScriptInterface<IAbilityInterface> Ability);

private:
    UPROPERTY()
    TArray<TScriptInterface<IAbilityInterface>> Abilities;

    UPROPERTY()
    TScriptInterface<IAbilityInterface> Equipped;
};

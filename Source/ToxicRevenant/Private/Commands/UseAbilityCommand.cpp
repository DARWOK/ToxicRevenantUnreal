// Fill out your copyright notice in the Description page of Project Settings.


#include "Commands/UseAbilityCommand.h"
#include "Engine/Engine.h"

void UUseAbilityCommand::Execute(APlayerCharacter* /*Character*/)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("[Command] UseAbility triggered"));
    }
    // Más adelante: Character->UseEquippedAbility();
}
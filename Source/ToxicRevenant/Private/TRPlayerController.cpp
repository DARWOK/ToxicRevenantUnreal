// Fill out your copyright notice in the Description page of Project Settings.


#include "TRPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Commands/UseAbilityCommand.h"
#include "PlayerCharacter.h"

ATRPlayerController::ATRPlayerController()
{
    UseAbilityCmd = CreateDefaultSubobject<UUseAbilityCommand>(TEXT("UseAbilityCommand"));
    // JumpCmd = CreateDefaultSubobject<UJumpCommand>(...);
}

void ATRPlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (!UseAbilityCmd)
    {
        UseAbilityCmd = NewObject<UUseAbilityCommand>(this);
    }

    if (ULocalPlayer* LP = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsys = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (DefaultMappingContext)
            {
                Subsys->AddMappingContext(DefaultMappingContext, /*Priority*/0);
            }
        }
    }
}

void ATRPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
    {
        if (IA_Fire)
        {
            EIC->BindAction(IA_Fire, ETriggerEvent::Triggered, this, &ATRPlayerController::OnFireTriggered);
        }
        // Bind Jump / Interact igual...
    }
}

void ATRPlayerController::OnFireTriggered(const FInputActionValue& /*Value*/)
{
    APlayerCharacter* PC = Cast<APlayerCharacter>(GetPawn());
    if (UseAbilityCmd && PC)
    {
        UseAbilityCmd->Execute(PC);
    }
}
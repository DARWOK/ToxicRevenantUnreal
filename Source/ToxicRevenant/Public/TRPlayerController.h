// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TRPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UCommand;

/**
 * 
 */
UCLASS()
class TOXICREVENANT_API ATRPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
    ATRPlayerController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* IA_Fire;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* IA_Jump;

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    UInputAction* IA_Interact;

private:
    UPROPERTY() UCommand* UseAbilityCmd;
    // UPROPERTY() UCommand* JumpCmd;
    // UPROPERTY() UCommand* InteractCmd;

    void OnFireTriggered(const struct FInputActionValue& Value);
    // void OnJumpTriggered(const FInputActionValue& Value);
    // void OnInteractTriggered(const FInputActionValue& Value);
};

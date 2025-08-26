// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class USampleCurrency;
class IPlayerStateInterface;
class IAbilityInterface;

UCLASS()
class TOXICREVENANT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	void UseEquippedAbility();
	void ChangeState(TScriptInterface<IPlayerStateInterface> NewState);
	void EquipAbility(TScriptInterface<IAbilityInterface> Ability);

private:
	UPROPERTY()
	TScriptInterface<IPlayerStateInterface> CurrentState;

	UPROPERTY()
	TScriptInterface<IAbilityInterface> EquippedAbility;

	UPROPERTY()
	USampleCurrency* Currency;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class UStatusEffect;

UCLASS()
class TOXICREVENANT_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();
	void ApplyEffect(UStatusEffect* Effect);
	void TakeDamage(float Amount);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	float Health = 100.0f;

	UPROPERTY()
	TArray<UStatusEffect*> ActiveEffects;

};

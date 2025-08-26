// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AreaEffect.generated.h"

class UStatusEffect;

UCLASS()
class TOXICREVENANT_API AAreaEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAreaEffect();
	void Initialize(float Radius, float Duration, UStatusEffect* EffectTemplate);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float DurationRemaining;
	float Radius;

	UPROPERTY()
	UStatusEffect* StatusEffectTemplate;

	void ApplyEffectToEnemies();
};

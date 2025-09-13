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
    // Daño “simple” utilitario (no oculta a APawn/ACharacter)
    UFUNCTION(BlueprintCallable)
    void TakeDamageSimple(float Amount);

    // Override correcto para que ApplyDamage/ApplyRadialDamage llamen aquí
    virtual float TakeDamage(
        float Damage,
        struct FDamageEvent const& DamageEvent,
        AController* EventInstigator,
        AActor* DamageCauser
    ) override;

    // --- Atributos mínimos usados en el .cpp ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    int32 Health = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float ToxinResistance = 0.f; // 0..100 (%)

    // Si tienes más propiedades/métodos, déjalos aquí
};

#include "Enemy.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

void AEnemy::TakeDamageSimple(float Amount)
{
    Health -= FMath::RoundToInt(Amount);
    if (Health <= 0)
    {
        // Aquí podrías notificar muerte / return-to-pool si ya lo tienes
        Destroy(); // AActor::Destroy (válido para ACharacter)
    }
}

float AEnemy::TakeDamage(
    float Damage,
    const FDamageEvent& DamageEvent,
    AController* EventInstigator,
    AActor* DamageCauser)
{
    // Enlaza el flujo “oficial” de Unreal con tu lógica simple
    TakeDamageSimple(Damage);
    return Damage; // Devuelve cuánto “consumiste”; ajusta si quieres
}

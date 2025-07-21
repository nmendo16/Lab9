// SpawnerComponent.cpp
#include "SpawnerComponent.h"
#include "TimerManager.h"
#include "Engine/World.h"

USpawnerComponent::USpawnerComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void USpawnerComponent::BeginPlay()
{
    Super::BeginPlay();
    SpawnChildren();
}

void USpawnerComponent::SpawnChildren()
{
    if (!ActorToSpawn) return;

    for (int32 i = 0; i < MaxSpawnCount; ++i)
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = GetOwner();
        FVector SpawnLocation = GetOwner()->GetActorLocation() + FVector(i * 100, 0, 0);
        AActor* Spawned = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
        if (Spawned)
        {
            FTimerHandle Timer;
            GetWorld()->GetTimerManager().SetTimer(Timer, [Spawned]()
                {
                    Spawned->Destroy();
                }, DespawnDelay, false);
        }
    }
}

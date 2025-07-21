// SpawnerComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnerComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOWTO_COMPONENTS_API USpawnerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USpawnerComponent();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> ActorToSpawn;

    UPROPERTY(EditAnywhere)
    int32 MaxSpawnCount = 3;

    UPROPERTY(EditAnywhere)
    float DespawnDelay = 5.f;

    void SpawnChildren();

private:
    int32 SpawnedCount = 0;
};

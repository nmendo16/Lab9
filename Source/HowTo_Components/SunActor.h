#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunActor.generated.h"

UCLASS()
class HOWTO_COMPONENTS_API ASunActor : public AActor

{
    GENERATED_BODY()

public:
    ASunActor();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, Category = "Satellite Spawning")
    TSubclassOf<AActor> SatelliteClass;

    UPROPERTY(EditAnywhere, Category = "Satellite Spawning")
    int32 SatelliteCount = 3;

    UPROPERTY(EditAnywhere, Category = "Satellite Spawning")
    float Radius = 300.0f; 

    void AttachSatellite(AActor* Satellite);
};

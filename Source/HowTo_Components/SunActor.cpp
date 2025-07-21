#include "SunActor.h"
#include "Engine/World.h"

ASunActor::ASunActor()
{
    PrimaryActorTick.bCanEverTick = false;

    UStaticMeshComponent* Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
}

void ASunActor::BeginPlay()
{
    Super::BeginPlay();

    if (!SatelliteClass) return;

    FVector Origin = GetActorLocation();

    for (int32 i = 0; i < SatelliteCount; ++i)
    {
        float Angle = i * (360.0f / SatelliteCount);
        float Radians = FMath::DegreesToRadians(Angle);
        FVector Offset = FVector(FMath::Cos(Radians), FMath::Sin(Radians), 0.f) * Radius;

        FVector SpawnLocation = Origin + Offset;
        FRotator SpawnRotation = FRotator::ZeroRotator;

        FActorSpawnParameters Params;
        Params.Owner = this;

        AActor* SpawnedSatellite = GetWorld()->SpawnActor<AActor>(SatelliteClass, SpawnLocation, SpawnRotation, Params);

        AttachSatellite(SpawnedSatellite);
    }
}

void ASunActor::AttachSatellite(AActor* Satellite)
{
    if (!Satellite || !RootComponent) return;

    Satellite->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
}

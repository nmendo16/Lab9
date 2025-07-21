#include "RotatingComponent.h"

URotatingComponent::URotatingComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void URotatingComponent::BeginPlay()
{
    Super::BeginPlay();
}

void URotatingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!GetOwner()) return;

    static float TotalTime = 0.f;
    TotalTime += DeltaTime;

    float Radius = 300.f;
    float Speed = 1.0f;

    AActor* Parent = GetOwner()->GetAttachParentActor();
    if (!Parent) return;

    FVector Center = Parent->GetActorLocation();
    FVector Offset;
    Offset.X = FMath::Cos(TotalTime * Speed) * Radius;
    Offset.Y = FMath::Sin(TotalTime * Speed) * Radius;

    FVector NewLocation = Center + Offset;
    GetOwner()->SetActorLocation(NewLocation);
}



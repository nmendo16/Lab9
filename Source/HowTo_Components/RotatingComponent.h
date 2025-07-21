#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "RotatingComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOWTO_COMPONENTS_API URotatingComponent : public USceneComponent
{
    GENERATED_BODY()

public:
    URotatingComponent();

protected:
    virtual void BeginPlay() override;

public:
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
    FRotator RotationSpeed = FRotator(0.f, 30.f, 0.f);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "CollidingPawnMovementComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class HOWTO_COMPONENTS_API UCollidingPawnMovementComponent : public UPawnMovementComponent
{
    GENERATED_BODY()

public:
    virtual void TickComponent(float DeltaTime, enum ELevelTick TickType,
        FActorComponentTickFunction* ThisTickFunction) override;
};

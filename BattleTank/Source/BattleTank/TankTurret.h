// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
private:
	float maxDegreesPerSecond;
	float maxRotationDegrees;
	float minRotationDegrees;
	float rotationChange;
	float turretNewYawValue;
	float turretNewYawValueClamped;


public:

	UTankTurret();
	void rotateTurret(float relativeSpeed);
	
};

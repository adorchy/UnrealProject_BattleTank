// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
	float maxDegreesPerSecond;
	float maxElevationDegrees;
	float minElevationDegrees;
	float elevationChange;
	float barrelNewPitchValue;
	float barrelNewPitchValueClamped;

public:
	UTankBarrel();
	void elevateBarrel(float relativeSpeed);


};

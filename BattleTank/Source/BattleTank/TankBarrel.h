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
	float maxElevationDegrees;
	float minElevationDegrees;

public:
	UTankBarrel();
	void elevateBarrel(float degreePerSeconds);


};

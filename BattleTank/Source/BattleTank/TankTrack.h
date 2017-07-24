// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force, and to apply force to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly)
		float trackMaxDrivingForce; // Max force per track in Newtons

public:
	UTankTrack();
	UFUNCTION(BlueprintCallable, Category = "Input")
		void setThrottle(float throttle);
	
	
};

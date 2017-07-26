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
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
		float trackMaxDrivingForce; // Max force per track in Newtons

public:
	UTankTrack();
	void applySideWaysForce();
	void driveTrack();
	UFUNCTION(BlueprintCallable, Category = "Input")
		void setThrottle(float throttle);
	
private:
	float currentThrottle;
	UFUNCTION ()
	void OnHit (UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};

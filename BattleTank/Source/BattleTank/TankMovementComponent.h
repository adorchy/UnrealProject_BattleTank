// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * Responsible from driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

	UTankTrack* rightTrack;
	UTankTrack* leftTrack;
	FVector tankOrientation;
	FVector tankDirectionIntention;

public:
	UTankMovementComponent();
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override; // Called from the pathfinding logic by the AI controllers

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void setTracksReference(UTankTrack* rightTrackToSet, UTankTrack* leftTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void intendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void intendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Input")
		void intendTurnLeft(float Throw);



};

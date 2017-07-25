// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"



UTankMovementComponent::UTankMovementComponent() {
	rightTrack = nullptr;
	leftTrack = nullptr;
	tankOrientation = { 0.0, 0.0, 0.0 };
	tankDirectionIntention = { 0.0, 0.0, 0.0 };
}


void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {

	// no need to call super as we're replacing the functionnality

	tankOrientation = GetOwner()->GetActorForwardVector().SafeNormal();
	tankDirectionIntention = MoveVelocity.SafeNormal();

	//UE_LOG(LogTemp, Warning, TEXT("Tank: %s - Velocity: %s"), *GetOwner()->GetName(), *tankDirectionIntention.ToString());
	auto forwardSpeed = FVector::DotProduct(tankOrientation, tankDirectionIntention);
	auto rotationSpeed = FVector::CrossProduct(tankOrientation, tankDirectionIntention);

	intendTurnLeft(-rotationSpeed.Z);
	intendMoveForward(forwardSpeed);
	
}


void UTankMovementComponent::setTracksReference(UTankTrack* rightTrackToSet, UTankTrack* leftTrackToSet) { 
		rightTrack = rightTrackToSet;
		leftTrack = leftTrackToSet;
}

void UTankMovementComponent::intendMoveForward(float Throw) {

	if (rightTrack && leftTrack) {
		rightTrack->setThrottle(Throw);
		leftTrack->setThrottle(Throw);
	}
}

void UTankMovementComponent::intendTurnRight(float Throw) {

	if (rightTrack && leftTrack) {
		rightTrack->setThrottle(-Throw);
		leftTrack->setThrottle(Throw);
	}
}

void UTankMovementComponent::intendTurnLeft(float Throw) {

	if (rightTrack && leftTrack) {
		rightTrack->setThrottle(Throw);
		leftTrack->setThrottle(-Throw);
	}
}

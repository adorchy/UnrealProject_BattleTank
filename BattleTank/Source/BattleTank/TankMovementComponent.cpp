// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"



UTankMovementComponent::UTankMovementComponent() {
	rightTrack = nullptr;
	leftTrack = nullptr;
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

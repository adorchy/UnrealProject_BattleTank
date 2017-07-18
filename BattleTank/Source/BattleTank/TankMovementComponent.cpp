// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankMovementComponent.h"
#include "TankTrack.h"



UTankMovementComponent::UTankMovementComponent() {
	rightTrack = nullptr;
	leftTrack = nullptr;

}

/*
void UTankMovementComponent::setTracksReference(UTankTrack* rightTrackToSet, UTankTrack* leftTrackToSet) {
rightTrack = rightTrackToSet;
leftTrack = leftTrackToSet;
}*/


void UTankMovementComponent::intendMoveForward(float Throw) {
	UE_LOG(LogTemp, Warning, TEXT("Intend move forward: %f"), Throw);

}

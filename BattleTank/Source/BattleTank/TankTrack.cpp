// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack() {

	trackMaxDrivingForce = 400000.0; // assume 40 tonnes tanks and 1 g accelration

}

void UTankTrack::setThrottle(float throttle) {

	UE_LOG(LogTemp, Warning, TEXT("%s : throttle value %f"), *GetName(), throttle);
	auto forceApplied = GetForwardVector()*throttle*trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast <UPrimitiveComponent> (GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
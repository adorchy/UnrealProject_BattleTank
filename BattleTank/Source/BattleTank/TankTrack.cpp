// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = true;
	trackMaxDrivingForce = 400000.0; // assume 40 tonnes tanks and 1 g accelration

}


void UTankTrack::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//calculate slipage speed
	auto slippageSpeed = FVector::DotProduct (GetRightVector(), GetComponentVelocity());
	auto correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();
	auto tankRootComponent = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRootComponent->GetMass() * correctionAcceleration)/2; // divide by 2 because 2 tracks
	tankRootComponent->AddForce(correctionForce);

}


void UTankTrack::setThrottle(float throttle) {
	//UE_LOG(LogTemp, Warning, TEXT("%s: %s : throttle value %f"), *GetOwner()->GetName(), *GetName(), throttle);
	auto forceApplied = GetForwardVector()*throttle*trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast <UPrimitiveComponent> (GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}
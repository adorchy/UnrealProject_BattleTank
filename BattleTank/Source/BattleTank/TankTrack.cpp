// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankTrack.h"


UTankTrack::UTankTrack() {
	PrimaryComponentTick.bCanEverTick = false;
	trackMaxDrivingForce = 400000.0; // assume 40 tonnes tanks and 1 g accelration
	currentThrottle = 0.0;
}

// Called when the game starts
void UTankTrack::BeginPlay() {
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);

}


void UTankTrack::applySideWaysForce() {

	float DeltaTime = GetWorld()->GetDeltaSeconds();
	//work out the required acceleration this frame to correct
	auto slippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	auto correctionAcceleration = -slippageSpeed / DeltaTime * GetRightVector();
	
	// Calculate and apply sideways (F = m*a)
	auto tankRootComponent = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto correctionForce = (tankRootComponent->GetMass() * correctionAcceleration) / 2; // divide by 2 because 2 tracks
	tankRootComponent->AddForce(correctionForce);
}


void UTankTrack::driveTrack() {

	//UE_LOG(LogTemp, Warning, TEXT("%s: %s : throttle value %f"), *GetOwner()->GetName(), *GetName(), throttle);
	auto forceApplied = GetForwardVector()*currentThrottle*trackMaxDrivingForce;
	auto forceLocation = GetComponentLocation();
	auto tankRoot = Cast <UPrimitiveComponent>(GetOwner()->GetRootComponent());
	tankRoot->AddForceAtLocation(forceApplied, forceLocation);

}

void UTankTrack::setThrottle(float throttle) {
	currentThrottle = FMath::Clamp<float>(currentThrottle + throttle, -1, 1);
}



void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
	//UE_LOG(LogTemp, Warning, TEXT("%s is hitting something!"), *GetName());
	
	driveTrack();
	applySideWaysForce();
	currentThrottle = 0;

}
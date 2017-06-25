// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "AimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Barrel = nullptr;
	launchVelocity = { 0.0, 0.0, 0.0 };
	projectileStartLocation = { 0.0, 0.0, 0.0 };
	collisionRadius = 0.0;
	

}


// Called when the game starts
void UAimingComponent::BeginPlay() {
	Super::BeginPlay();

}


// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


void UAimingComponent::AimAt(FVector hitLocation, float launchSpeed) {

	if (Barrel) {
		projectileStartLocation = Barrel->GetSocketLocation(FName("Muzzle"));
		// UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s!"), *GetOwner()->GetName(), *hitLocation.ToString(), *Barrel->GetComponentLocation().ToString());

		if (UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OUT launchVelocity,
			projectileStartLocation,
			hitLocation,
			launchSpeed,
			false,
			collisionRadius,
			0.0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		) == true)

		{
			auto AimDirection = launchVelocity.GetSafeNormal(); // Gets a normalized copy of the vector
			UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s!"), *GetOwner()->GetName(), *AimDirection.ToString(), *Barrel->GetComponentLocation().ToString());
			MoveBarrel();
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("Error with function SuggestProjectileVelocity in AimingComponent.ccp, wrong arguments used"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Error no Barrel found, check Tank_BP:Imput Setup"));
	}
}


void UAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UAimingComponent::MoveBarrel() {
	
	/* Work-out difference between current barrel direction and aim direction*/
	FRotator barrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator aimRotator = launchVelocity.Rotation();
	FRotator deltaRotator = aimRotator - barrelRotator;
	Barrel->elevateBarrel(deltaRotator.Pitch);
	

}
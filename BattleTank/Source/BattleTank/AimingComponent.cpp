// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "AimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Barrel = nullptr;
	Turret = nullptr;
	launchVelocity = { 0.0, 0.0, 0.0 };
	projectileStartLocation = { 0.0, 0.0, 0.0 };
	collisionRadius = 0.0;
	tankFiringState = EFiringState::isBarrelMoving;
	reloadTime = 2.0;
	lastFireTime = 0.0;
	projectileLaunchSpeed = 10000;
	barrelRotator = { 0.0, 0.0, 0.0 };
	aimRotator = { 0.0, 0.0, 0.0 };
	ammoNumber = 150;

}


// Called when the game starts
void UAimingComponent::BeginPlay() {
	Super::BeginPlay();

}


// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ammoNumber != 0) {
		if ((lastFireTime + reloadTime) < GetWorld()->GetTimeSeconds()) {
			if (barrelRotator.Equals(aimRotator, 10.0)) {
				tankFiringState = EFiringState::isReady;

			}
			else {
				tankFiringState = EFiringState::isBarrelMoving;
			}
		}
	}

}


// used in Tank_BP and in tank.cpp
void UAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	// test
		Barrel = BarrelToSet;
}

// used in Tank_BP and in tank.cpp
void UAimingComponent::SetTurretReference(UTankTurret* TurrelToSet) {
		Turret = TurrelToSet;
}

//Compute launchVelocity
void UAimingComponent::AimAt(FVector hitLocation, float launchSpeed) {

	if (Barrel && Turret) {
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
			/* 
			auto AimDirection = launchVelocity.GetSafeNormal(); // Gets a normalized copy of the vector
			UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s!"), *GetOwner()->GetName(), *AimDirection.ToString(), *Barrel->GetComponentLocation().ToString());
			*/ 
			MoveBarrelAndTurret();
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("Error with function SuggestProjectileVelocity in AimingComponent.ccp, wrong arguments used"));
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Error no Barrel or Turrel found, check Tank_BP:Imput Setup"));
	}
}


void UAimingComponent::MoveBarrelAndTurret() {
	
	if (Barrel && Turret) {

	/* Work-out difference between current barrel direction and aim direction*/
	barrelRotator = Barrel->GetForwardVector().Rotation();
	aimRotator = launchVelocity.Rotation();
	FRotator deltaRotator = aimRotator - barrelRotator;

	Barrel->elevateBarrel(deltaRotator.Pitch);

	if (FMath::Abs(deltaRotator.Yaw) < 180) {
		Turret->rotateTurret(deltaRotator.Yaw);
	}
	else {
		Turret->rotateTurret(-deltaRotator.Yaw);
	}
	}
}


void UAimingComponent::Fire() {
	if (ensure(Barrel)) {
		if (tankFiringState != EFiringState::isReloading &&
			tankFiringState != EFiringState::isOutOfAmmo) {

			//UE_LOG(LogTemp, Warning, TEXT("Tank is firing!"));
			auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBluePrint, Barrel->GetSocketLocation(FName("Muzzle")), Barrel->GetSocketRotation(FName("Muzzle")));
			
			if (ensure(projectile)) {
			projectile->launchProjectile(projectileLaunchSpeed);
			lastFireTime = GetWorld()->GetTimeSeconds();
			ammoNumber--;
			if (ammoNumber == 0) {
				tankFiringState = EFiringState::isOutOfAmmo;
			}
			else {
				tankFiringState = EFiringState::isReloading;
			}
			}
		}
	}

}

EFiringState UAimingComponent::getFiringState() const {

	return tankFiringState;

}
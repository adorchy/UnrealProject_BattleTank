// Copyright Arnaud D_ORCHYMONT


#include "BattleTank.h"
#include "Tank.h"
#include "AimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming Component")); // add the UAiming component class to the tank bluebrint class.
	Barrel = nullptr;
	reloadTime = 3.0;
	lastFireTime = 0.0;
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// used by TankAIController.h and TankPlayerController.h rely on the procedure AimAt declared in AimingComponent.h.
void ATank::AimAt(FVector hitLocation) {
	TankAimingComponent->AimAt(hitLocation, launchSpeed);
}

// used in Tank_BP
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

// used in Tank_BP
void ATank::SetTurretReference(UTankTurret* TurrelToSet) {
	TankAimingComponent->SetTurretReference(TurrelToSet);

}

void ATank::Fire() {

	if (Barrel) {
		if ((lastFireTime + reloadTime) < GetWorld()->GetTimeSeconds()){


		UE_LOG(LogTemp, Warning, TEXT("Tank is firing v2!"));
		auto projectile = GetWorld()->SpawnActor<AProjectile>(projectileBluePrint, Barrel->GetSocketLocation(FName("Muzzle")), Barrel->GetSocketRotation(FName("Muzzle")));
		projectile->launchProjectile(launchSpeed);
		lastFireTime = GetWorld()->GetTimeSeconds(); 
		}
	} 
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("Error: Barrel pointer is null, see Tank.h"));
	}

	

}

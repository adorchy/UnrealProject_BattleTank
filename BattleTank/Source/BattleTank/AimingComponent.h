// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

//enum for aiming state
UENUM()
enum class EFiringState : uint8 {
	isOutOfAmmo,
	isReloading,
	isBarrelMoving,
	isReady
};


class UTankBarrel;
class UTankTurret;
class AProjectile;

/**
*Compute a launch velocity for a projectile to hit a specified point.
*Compute (use the launch velocity) the rotation required to move the barrel and the turret toward the direction where the player is aiming.
*Monitores the tank firing state. There is 4 differentes states: "isOutOfAmmo", "isReloading", "isBarrelMoving", "isReady". These states are used to determine the player's aiming reticule color and are also used to determine when AI and player are allowed to fire.
*Fire a projectile, i.e. spawn and launch an object.
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UAimingComponent : public UActorComponent {
	GENERATED_BODY()



protected:
	
	virtual void BeginPlay() override; // Called when the game starts

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState tankFiringState;

	UPROPERTY(EditAnywhere, Category = "Setup")
		TSubclassOf<AProjectile> projectileBluePrint;

	UPROPERTY(BlueprintReadOnly, Category = "Firing")
		int32 ammoNumber;

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetTurretReference(UTankTurret* TurrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();
	/*
	*
	*/
	UAimingComponent(); // Sets default values for this component's properties
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override; // Called every frame
	void AimAt(FVector hitLocation, float launchSpeed);
	void MoveBarrelAndTurret();
	EFiringState getFiringState() const;


private:

	UTankBarrel* Barrel; // Pointer initialized in Tank_BP (Imput Setup)
	UTankTurret* Turret; // Pointer initialized in Tank_BP (Imput Setup)
	FVector launchVelocity;
	FVector projectileStartLocation;
	float collisionRadius;
	float reloadTime;
	float lastFireTime;
	float projectileLaunchSpeed;
	FRotator barrelRotator;
	FRotator aimRotator;
	
};
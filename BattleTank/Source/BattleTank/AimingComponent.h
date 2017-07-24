// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

//enum for aiming state
UENUM()
enum class EFiringState : uint8 {
	isReloading,
	isBarrelMoving,
	isReady
};


class UTankBarrel;
class UTankTurret;

/**
*
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UAimingComponent : public UActorComponent {
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState tankFiringState;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void SetTurretReference(UTankTurret* TurrelToSet);
	/*
	*
	*/
	void AimAt(FVector hitLocation, float launchSpeed);
	void MoveBarrelAndTurret();


private:

	UTankBarrel* Barrel; // Pointer initialized in Tank_BP (Imput Setup)
	UTankTurret* Turret; // Pointer initialized in Tank_BP (Imput Setup)
	FVector launchVelocity;
	FVector projectileStartLocation;
	float collisionRadius;

	
};
// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"

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

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	void AimAt(FVector hitLocation, float launchSpeed);
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurrelToSet);
	void MoveBarrelAndTurret();


private:

	UTankBarrel* Barrel; // Pointer initialized in Tank_BP (Imput Setup)
	UTankTurret* Turret; // Pointer initialized in Tank_BP (Imput Setup)
	FVector launchVelocity;
	FVector projectileStartLocation;
	float collisionRadius;
	
};
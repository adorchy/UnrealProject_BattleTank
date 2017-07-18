// Copyright Arnaud D_ORCHYMONT

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UAimingComponent;
class AProjectile;
class UTankBarrel;
class UTankMovementComponent;


/*
Class Tank, uses the class AimingComponent and is used by Tank_BP as parent class.
Ensure the link Between the classes AimingComponent and the Controller classes.
OUPUT: hitResult
*/
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

	UTankBarrel* Barrel; //// local barrel reference for spawning projectile
	float reloadTime; 
	float lastFireTime;

public:	
	ATank(); // Sets default values for this pawn's properties
	virtual void Tick(float DeltaTime) override; // Called every frame
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Called to bind functionality to input
	
	void AimAt(FVector hitLocation); // used by TankAIController.h and TankPlayerController.h rely on the procedure AimAt declared in AimingComponent.h.
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet); // used in Tank_BP
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurrelToSet); // used in Tank_BP
	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();
	
protected:
	virtual void BeginPlay() override; // Called when the game starts or when spawned
	UAimingComponent* TankAimingComponent;
	
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float launchSpeed = 10000; // speed of 1000 m/s TODO: find sensible value
	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> projectileBluePrint;


};

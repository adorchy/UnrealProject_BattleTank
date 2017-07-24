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


public:	
	ATank(); // Sets default values for this pawn's properties
	virtual void Tick(float DeltaTime) override; // Called every frame
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Called to bind functionality to input
	
	//void AimAt(FVector hitLocation); // used by TankAIController.h and TankPlayerController.h rely on the procedure AimAt declared in AimingComponent.h.
	

	
protected:
	virtual void BeginPlay() override; // Called when the game starts or when spawned

	UPROPERTY(BlueprintReadOnly)
	UAimingComponent* TankAimingComponent;
	
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float launchSpeed = 10000; // speed of 1000 m/s TODO: find sensible value




};

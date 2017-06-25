// Copyright Arnaud D_ORCHYMONT

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UAimingComponent;

/*
Class Tank, uses the class AimingComponent and is used by Tank_BP as parent class.
Ensure the link Between the classes AimingComponent and the Controller classes.
OUPUT: hitResult
*/
UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Called to bind functionality to input
	void AimAt(FVector hitLocation); // used by TankAIController.h and TankPlayerController.h rely on the procedure AimAt declared in AimingComponent.h.
	
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet); // used in Tank_BP
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurrelToSet); // used in Tank_BP
	
protected:
	UAimingComponent* TankAimingComponent;
	UPROPERTY(EditAnywhere)
	float launchSpeed = 10000; // speed of 1000 m/s TODO: find sensible value

};

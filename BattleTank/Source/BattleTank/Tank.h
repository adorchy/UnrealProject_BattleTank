/*

Class Tank, uses the class AimingComponent and is used by Tank_BP as parent class.
Ensure the link Between the classes AimingComponent and the Controller classes.
OUPUT: hitResult

*/

#pragma once

#include "AimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector hitLocation); // used by TankAIController.h and TankPlayerController.h rely on the procedure AimAt declared in AimingComponent.h.
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet); // used in Tank_BP
	
protected:
	UAimingComponent* TankAimingComponent;
	UPROPERTY(EditAnywhere)
		float launchSpeed = 100000; // speed of 1000 m/s TODO: find sensible value

};

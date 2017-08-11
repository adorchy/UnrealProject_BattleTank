// Copyright Arnaud D_ORCHYMONT

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//enum for aiming state
UENUM()
enum class EHealthState : uint8 {
	dead,
	low,
	half,
	high
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

class UAimingComponent;
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

		


public:	
	ATank(); // Sets default values for this pawn's properties
	virtual void Tick(float DeltaTime) override; // Called every frame
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; // Called to bind functionality to input
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override; // called by the engine when damage is dealt
	EHealthState getHealthState() const;
	FTankDelegate onTankDeath;


	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

protected:
	virtual void BeginPlay() override; // Called when the game starts or when spawned

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float tankStartingHP; 

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EHealthState tankHealthState;

private:
	float tankCurrentHP;
	bool isTankAlive;



};

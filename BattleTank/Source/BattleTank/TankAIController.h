// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"
/*
Class TankAIController, rely on "Tank" class.
Used to compute the coordinates of the location of the tank controlled by the player.
It uses the procedure "AimAt" declared in Tank.h.
OUPUT: playerTankLocation
*/
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override; // Called every frame
	ATankAIController();
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	void GetPlayerTankLocation();

private:
	ATank* controlledTank;
	ATank* playerTank;
	FVector playerTankLocation;
	
	
};

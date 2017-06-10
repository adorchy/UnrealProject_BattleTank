// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
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

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	ATankPlayerController();
	virtual void Tick(float DeltaTime) override; // Called every frame
	ATank* GetControlledTank() const;
	void ComputeCrossHairPosition();
	void ComputeViewPointDirection();
	void ComputeReachLineEnd();
	void DrawRedDebugLineFromPawn();
	void AimTowardsCrossHair();

	
private:
	ATank* ControlledTank;
	FVector ViewPointLocation;
	FVector ViewPointDirection;
	FVector LineTraceEnd;
	float reach;
	float crossHairPositionX;
	float crossHairPositionY;
};

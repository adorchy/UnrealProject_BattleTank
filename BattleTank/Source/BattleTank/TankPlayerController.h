// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * Allow the player to aim at terrain and actors.
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
	void ComputeViewPointLocation();
	void ComputeLineTraceEnd();
	bool LineTrace();
	void DrawRedDebugLineFromCrossHair();
	void AimTowardsCrossHair();

	
private:
	ATank* ControlledTank;
	FVector ViewPointLocation;
	FVector ViewPointDirection;
	FVector LineTraceEnd;
	float crossHairPositionX;
	float crossHairPositionY;
	float lineTraceRange;
	FHitResult hitResult;
};

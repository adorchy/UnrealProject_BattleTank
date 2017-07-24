// Copyright Arnaud D_ORCHYMONT

#pragma once


#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UAimingComponent;
class ATank;


/*
Class TankPlayerController, rely on "Tank" class and used by TankPlayerController_BP as parent class.
Used to compute the coordinates of the location aimed by the crosshair.
It uses the procedure "AimAt" declared in Tank.h.
OUPUT: hitResult
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UAimingComponent* myAimingComponent);

public:
	ATankPlayerController();
	virtual void Tick(float DeltaTime) override; // Called every frame
	void ComputeCrossHairPosition();
	void ComputeViewPointDirection();
	void ComputeViewPointLocation();
	void ComputeLineTraceEnd();
	bool LineTrace();
	void DrawRedDebugLineFromCrossHair();

	
private:
	ATank* ControlledTank;
	UAimingComponent* tankAimingComponent;
	FVector ViewPointLocation;
	FVector ViewPointDirection;
	FVector LineTraceEnd;
	float crossHairPositionX;
	float crossHairPositionY;
	float lineTraceRange;
	FHitResult hitResult;
};

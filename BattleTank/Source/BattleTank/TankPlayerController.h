/* 

Class TankPlayerController, rely on "Tank" class and used by TankPlayerController_BP as parent class. 
Used to compute the coordinates of the location aimed by the crosshair.
It uses the procedure "AimAt" declared in Tank.h.
OUPUT: hitResult

*/ 

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


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

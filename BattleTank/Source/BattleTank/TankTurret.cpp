// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankTurret.h"


UTankTurret::UTankTurret() {
	maxDegreesPerSecond = 15.0;
	maxRotationDegrees = 170.0;
	minRotationDegrees = -170.0;
	rotationChange = 0.0;
	turretNewYawValue = 0.0;
	turretNewYawValueClamped = 0.0;
}


void UTankTurret::rotateTurret(float relativeSpeed) {

	relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0, 1.0);
	rotationChange = relativeSpeed*maxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	turretNewYawValue = RelativeRotation.Yaw + rotationChange;
	turretNewYawValueClamped = FMath::Clamp<float>(turretNewYawValue, minRotationDegrees, maxRotationDegrees);

	FRotator turretRotation = {0.0, turretNewYawValueClamped, 0.0};
	SetRelativeRotation(turretRotation);
}



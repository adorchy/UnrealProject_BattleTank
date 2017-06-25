// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankBarrel.h"


UTankBarrel::UTankBarrel() {
	maxElevationDegrees = 40.0;
	minElevationDegrees = 0.0;
	maxDegreesPerSecond = 8.0;
	elevationChange = 0.0;
	barrelNewPitchValue = 0.0;
	barrelNewPitchValueClamped = 0.0;
}

/*
PURPOSE: Move the barrel
OUTPUT: 
*/
void UTankBarrel::elevateBarrel(float relativeSpeed) {

		relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0, 1.0); // 1 is max downward speed and +1 is max up movement
		elevationChange = relativeSpeed*maxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
		barrelNewPitchValue = RelativeRotation.Pitch + elevationChange;
		barrelNewPitchValueClamped = FMath::Clamp<float>(barrelNewPitchValue, minElevationDegrees, maxElevationDegrees);

		FRotator barrelRotation = { barrelNewPitchValueClamped, 0.0, 0.0 };
		SetRelativeRotation(barrelRotation);

}
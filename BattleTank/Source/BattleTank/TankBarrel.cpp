// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankBarrel.h"


UTankBarrel::UTankBarrel() {
	maxElevationDegrees = 40.0;
	minElevationDegrees = 0.0;
	maxDegreesPerSecond = 5.0;


}

/*
PURPOSE: Move the barrel
OUTPUT: 
*/
void UTankBarrel::elevateBarrel(float relativeSpeed) {

		relativeSpeed = FMath::Clamp<float>(relativeSpeed, -1.0, 1.0);
		auto elevationChange = relativeSpeed*maxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
		auto barrelNewPitchValue = RelativeRotation.Pitch + elevationChange;
		auto barrelClampedNewPitchValue = FMath::Clamp<float>(barrelNewPitchValue, minElevationDegrees, maxElevationDegrees);


		FRotator barrelRotation = { barrelClampedNewPitchValue , 0.0, 0.0 };
		SetRelativeRotation(barrelRotation);

}
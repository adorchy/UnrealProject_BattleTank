// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h"


ATankPlayerController::ATankPlayerController() {
	ControlledTank = nullptr;
	ViewPointLocation = { 0.0,0.0,0.0 };
	ViewPointDirection = { 0.0,0.0,0.0 };
	LineTraceEnd = { 0.0,0.0,0.0 };
	crossHairPositionX=0.0;
	crossHairPositionY=0.0;
	lineTraceRange = 1000000.0;
	
}

// Called when the game starts
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ControlledTank=GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankPlayerController.cpp: no tank controlled!"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("you are controlling %s!"), *ControlledTank->GetName());
	}
	ComputeCrossHairPosition();
}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (LineTrace() == true) {
		if (ControlledTank) {
			GetControlledTank()->AimAt(hitResult.Location);
		}
	}	
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}

/*
PURPOSE: Compute crossHair Position, in our case, crossHair is positionned middle of Viewport's width (X) and 
firt third part of Viewport's height (Y)
OUTPUT: crossHairPositionX and crossHairPositionY
*/
void ATankPlayerController::ComputeCrossHairPosition() {
	int32  ViewportSizeX=0, ViewportSizeY=0;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	crossHairPositionX = ViewportSizeX*0.5;
	crossHairPositionY = ViewportSizeY*0.3333;
	// UE_LOG(LogTemp, Warning, TEXT("CrossHair position, X: %f, Y: %f"), crossHairPositionX, crossHairPositionY);
}

/*
PURPOSE: Compute ViewPointDirection, used to compute the End location of the ray 
OUTPUT: ViewPointDirection
*/
void ATankPlayerController::ComputeViewPointDirection() {
	FVector WorldLocation;
	DeprojectScreenPositionToWorld
	(
		crossHairPositionX,
		crossHairPositionY,
		WorldLocation,
		OUT ViewPointDirection
	);
	ViewPointDirection*=lineTraceRange;
	// UE_LOG(LogTemp, Warning, TEXT("View point direction: %s"), *ViewPointDirection.ToString());
}

/*
PURPOSE: Compute ViewPointLocation, used to compute the End location of the ray
OUTPUT: ViewPointLocation
*/
void ATankPlayerController::ComputeViewPointLocation() {
	ViewPointLocation=PlayerCameraManager->GetCameraLocation();
}

/*
PURPOSE: Compute LineTraceEnd, used to trace a ray against the world 
OUTPUT: LineTraceEnd
*/
void ATankPlayerController::ComputeLineTraceEnd() {
	ComputeViewPointDirection();
	ComputeViewPointLocation();
	LineTraceEnd = ViewPointDirection + ViewPointLocation;
}

/*
PURPOSE: Trace a ray against the world using a specific channel and return the first blocking hit 
OUTPUT: hitResult
*/
bool ATankPlayerController::LineTrace() {
	ComputeLineTraceEnd();
	if (GetWorld()->LineTraceSingleByChannel(
		OUT hitResult,
		ViewPointLocation,
		LineTraceEnd,
		ECollisionChannel::ECC_Visibility
	) == true) {
		return true;
	}
	return false;
}

/*
PURPOSE: Debug Tool, check if ViewPointLocation and LineTraceEnd are computed correctly
*/
void ATankPlayerController::DrawRedDebugLineFromCrossHair() {
	DrawDebugLine(GetWorld(), ViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.0, 0.0, 10.0);
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h"


ATankPlayerController::ATankPlayerController() {
	ControlledTank = nullptr;
	ViewPointLocation = { 0.0,0.0,0.0 };
	ViewPointDirection = { 0.0,0.0,0.0 };
	LineTraceEnd = { 0.0,0.0,0.0 };
	reach= 6000;
	crossHairPositionX=0.0;
	crossHairPositionY=0.0;
	
}

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
	UE_LOG(LogTemp, Warning, TEXT("CrossHair position, X: %f, Y: %f"), crossHairPositionX, crossHairPositionY);
}


void ATankPlayerController::ComputeViewPointDirection() {



}


void ATankPlayerController::ComputeReachLineEnd() {

}

void ATankPlayerController::DrawRedDebugLineFromPawn() {
	DrawDebugLine(GetWorld(), ViewPointLocation, LineTraceEnd, FColor(255, 0, 0), false, 0.0, 0.0, 10.0);
}

void ATankPlayerController::AimTowardsCrossHair() {

	if (ControlledTank) {

	}
}


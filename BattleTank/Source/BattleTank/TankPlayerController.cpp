// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankPlayerController.h"


ATankPlayerController::ATankPlayerController() {
	ControlledTank = nullptr;
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ControlledTank=GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankPlayerController.cpp: no tank controlled!"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("you are controlling %s!"), *ControlledTank->GetName());
	}
}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}



// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



ATankAIController::ATankAIController() {
	ControlledTank = nullptr;
	PlayerTank = nullptr;
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	ControlledTank = GetControlledTank();
	PlayerTank = GetPlayerTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankAIController.cpp: no tank controlled!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI is controlling %s!"), *ControlledTank->GetName());
	}

	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankAIController.cpp: AI can't find player tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI has found player tank: %s!"), *PlayerTank->GetName());
	}

}

ATank* ATankAIController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}


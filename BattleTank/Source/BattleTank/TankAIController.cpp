// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



ATankAIController::ATankAIController() {
	controlledTank = nullptr;
	playerTank = nullptr;
	playerTankLocation = { 0.0,0.0,0.0 };
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	controlledTank = GetControlledTank();
	if (!controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankAIController.cpp: no tank controlled!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI is controlling %s!"), *controlledTank->GetName());
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	GetPlayerTankLocation();
}



ATank* ATankAIController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}

void ATankAIController::GetPlayerTankLocation() {
	playerTank=GetPlayerTank();
	if (!playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankAIController.cpp: AI can't find player tank!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI has found player tank: %s!"), *playerTank->GetName());
		playerTankLocation = playerTank->GetTargetLocation();
		controlledTank->AimAt(playerTankLocation); // AimAt is a procedure declared in Tank.h
	}
}


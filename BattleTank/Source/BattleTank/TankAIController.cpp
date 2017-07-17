// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"



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

	playerTank = GetPlayerTank();
	if (!playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Error in TankAIController.cpp: AI can't find player tank!"));
	}
}

// Called every frame
void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (playerTank && controlledTank) {
		playerTankLocation = playerTank->GetTargetLocation();
		controlledTank->AimAt(playerTankLocation);
		controlledTank->Fire();
		}

}


ATank* ATankAIController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}



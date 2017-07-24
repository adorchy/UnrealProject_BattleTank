// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"
#include "AimingComponent.h"



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

		//Movement
		MoveToActor(playerTank, 1000); // stay at least at 100 m from player Tank

		// Fire
		playerTankLocation = playerTank->GetTargetLocation();
		//controlledTank->AimAt(playerTankLocation);
		controlledTank->FindComponentByClass<UAimingComponent>()->AimAt(playerTankLocation, 10000);
		//controlledTank->Fire();
		}

}


ATank* ATankAIController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}



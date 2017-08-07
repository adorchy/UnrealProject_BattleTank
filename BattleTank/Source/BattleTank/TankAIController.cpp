// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"
#include "AimingComponent.h"

//Depends on movement component via pathfinding system

ATankAIController::ATankAIController() {
	controlledPawn = nullptr;
	playerTank = nullptr;
	tankAimingComponent = nullptr;
	playerTankLocation = { 0.0,0.0,0.0 };
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	controlledPawn = GetControlledTank();
	playerTank = GetPlayerTank();
	if (ensure(controlledPawn)) {
		tankAimingComponent = controlledPawn->FindComponentByClass<UAimingComponent>();
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (playerTank && controlledPawn) {

		//Movement
		MoveToActor(playerTank, 8000.0); // stay at least at 8 000 m from player Tank

		// Fire
		playerTankLocation = playerTank->GetTargetLocation();
		if (ensure(tankAimingComponent)) {
			tankAimingComponent->AimAt(playerTankLocation, 10000);
			if (tankAimingComponent->getFiringState() == EFiringState::isReady) {
				//tankAimingComponent->Fire();
			}
			
		}
	}

}


APawn* ATankAIController::GetControlledTank() const {

	return GetPawn();
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}



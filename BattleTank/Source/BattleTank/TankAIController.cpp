// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "TankAIController.h"
#include "Tank.h"
#include "AimingComponent.h"

//Depends on movement component via pathfinding system

ATankAIController::ATankAIController() {
	controlledTank = nullptr;
	playerTank = nullptr;
	tankAimingComponent = nullptr;
	playerTankLocation = { 0.0,0.0,0.0 };
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	controlledTank = GetControlledTank();
	playerTank = GetPlayerTank();
	if (ensure(controlledTank)) {
		tankAimingComponent = controlledTank->FindComponentByClass<UAimingComponent>();
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (playerTank && controlledTank) {

		//Movement
		MoveToActor(playerTank, 8000.0); // stay at least at 100 m from player Tank

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


ATank* ATankAIController::GetControlledTank() const {

	return Cast <ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast <ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

}



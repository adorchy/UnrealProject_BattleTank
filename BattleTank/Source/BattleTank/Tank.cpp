// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UAimingComponent>(FName ("Aiming Component")); // add the UAiming component class to the tank bluebrint class.

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector hitLocation)
{
	TankAimingComponent->AimAt(hitLocation);
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at actor: %s!"), *ourTank, *hitResult.GetActor()->GetName());
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at actor: %s!"), *ourTank, *hitResult.GetActor()->GetTargetLocation().ToString());
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);


}


// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "AimingComponent.h"


// Sets default values for this component's properties
UAimingComponent::UAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Barrel = nullptr;

	// ...
}


// Called when the game starts
void UAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UAimingComponent::AimAt(FVector hitLocation) {
	UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s from %s!"), *GetOwner()->GetName(), *hitLocation.ToString(), *Barrel->GetComponentLocation().ToString());
}


void UAimingComponent::SetBarrelReference(UStaticMeshComponent* BarrelToSet) {
	Barrel = BarrelToSet;
}
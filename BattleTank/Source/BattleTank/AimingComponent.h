// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:

	void AimAt(FVector hitLocation, float launchSpeed);
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:

	UStaticMeshComponent* Barrel; 
	FVector launchVelocity;
	FVector projectileStartLocation;
	float collisionRadius;


	
};

// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UProjectileMovementComponent* projectileMovementComponent;

public:	
	AProjectile(); // Sets default values for this actor's properties
	virtual void Tick(float DeltaTime) override; // Called every frame
	
	void launchProjectile(float speed);

	
	
};

// Copyright Arnaud D_ORCHYMONT

#pragma once

#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

/*
*
*
*/
UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UProjectileMovementComponent* projectileMovementComponent;

	UPROPERTY(VisibleAnywhere, category = "Components")
		UStaticMeshComponent* collisionMesh;

	UPROPERTY(VisibleAnywhere, category = "Components")
		UParticleSystemComponent* launchBlast;

	UPROPERTY(VisibleAnywhere, category = "Components")
		UParticleSystemComponent* impactBlast;

	UPROPERTY(VisibleAnywhere, category = "Components")
		URadialForceComponent* explosionForce;
	
	UPROPERTY(EditDefaultsOnly, category = "Setup")
		float destroyDelay;

	UPROPERTY(EditDefaultsOnly, category = "Setup")
		float projectileDamage;

private:
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

public:	
	AProjectile(); // Sets default values for this actor's properties
	virtual void Tick(float DeltaTime) override; // Called every frame

	void launchProjectile(float speed);
	void onTimerExpire();

	
};

// Copyright Arnaud D_ORCHYMONT

#include "BattleTank.h"
#include "Projectile.h"



// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileMovementComponent = nullptr;
	collisionMesh = nullptr;
	launchBlast = nullptr;
	impactBlast = nullptr;

	projectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));

	if (ensure(projectileMovementComponent)) {
	projectileMovementComponent->Deactivate();
	}

	collisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	if (ensure(collisionMesh)) {
		SetRootComponent(collisionMesh);
		collisionMesh->SetNotifyRigidBodyCollision(true); // can be also edited in BP
		collisionMesh->SetVisibility(false); // can be also edited in BP
	}

	launchBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Launch Blast"));
	if (ensure(launchBlast)) {
		launchBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	}

	impactBlast = CreateDefaultSubobject<UParticleSystemComponent>(FName("Impact Blast"));
	if (ensure(impactBlast)) {
		impactBlast->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		impactBlast->bAutoActivate=false;
	}
	/**/


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	collisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AProjectile::launchProjectile(float speed) {
	if (ensure(projectileMovementComponent)) {
		projectileMovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector*speed);
		projectileMovementComponent->Activate();
	}
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit) {
	launchBlast->Deactivate();

	impactBlast->Activate();



}



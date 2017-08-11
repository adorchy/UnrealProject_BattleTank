// Copyright Arnaud D_ORCHYMONT


#include "BattleTank.h"
#include "Tank.h"



// Sets default values
ATank::ATank() {
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//TankAimingComponent = CreateDefaultSubobject<UAimingComponent>(FName("Aiming Component")); // add the UAiming component class to the tank bluebrint class.
	tankStartingHP = 100;
	tankCurrentHP = tankStartingHP;
	tankHealthState = EHealthState::high;
	isTankAlive = true;
}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) {
	float damageToApply = FMath::Clamp<float>(DamageAmount, 0.0, tankCurrentHP);
	//UE_LOG(LogTemp, Warning, TEXT("tank: %s has now %f HP"), *GetName(), tankCurrentHP);
	tankCurrentHP -= damageToApply;
	if (tankCurrentHP < 75.0) {
		if (tankCurrentHP > 25) {
			tankHealthState = EHealthState::half;
		}
		else {
			tankHealthState = EHealthState::low;
		}
	}

	if (tankCurrentHP < 0.5 && isTankAlive == true) {
		isTankAlive = false;
		onTankDeath.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("Tank has no more HP"));
	}

	return damageToApply;

}

float ATank::GetHealthPercent() const {
	return tankCurrentHP / tankStartingHP;

}

EHealthState ATank::getHealthState() const {

	return tankHealthState;
}



// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed)
{
<<<<<<< HEAD

=======
>>>>>>> parent of a013852... Revert "Tahtays ja ammuksen lahto suunta asennettu."
	if (!Barrel) { return;}

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
		

	if(bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}
<<<<<<< HEAD

	
	UE_LOG(LogTemp, Warning, TEXT("Firing at %F"), LaunchSpeed);

=======
>>>>>>> parent of a013852... Revert "Tahtays ja ammuksen lahto suunta asennettu."
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

}


// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
	}
}

 void ATankPlayerController::Tick(float DeltaTime)
 {
	 Super::Tick(DeltaTime);
	 AimTowardCrosshair();
 }

ATank* ATankPlayerController::GetControlledTank() const 
{
	 return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) 
	{
		return;
	}

	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *OutHitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	return true;
}

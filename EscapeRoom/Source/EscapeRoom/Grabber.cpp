// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

#define OUT  

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("Grabber Is Active"));
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// Get player viewport
	FVector pvLocation;
	FRotator pvRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT pvLocation, OUT pvRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Location: %s || Rotation: %s"), *pvLocation.ToString(), *pvRotation.ToString());

	// ray-cast maxDist to obj
	/*FVector lineTraceEnd = pvLocation + FVector(0.0f, 0.0f, maxReach);*/
	/*DrawDebubLine(
		GetWorld(),

	);*/
	FVector lineTraceEnd = pvLocation + pvRotation.Vector() * maxReach;
	DrawDebugLine(GetWorld(), pvLocation, lineTraceEnd, debugLineColor, false, 0.0f, 0.0f, 10.0f);
	
	//GetWorld()->



}


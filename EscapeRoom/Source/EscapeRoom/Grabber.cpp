// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Grabber.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

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

	SetPhysicsHandleComponent();
	SetInputComponent();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (physicsHandle->GrabbedComponent) {
		FVector pvLocation;
		FRotator pvRotation;
		GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT pvLocation, OUT pvRotation);
		//UE_LOG(LogTemp, Warning, TEXT("Location: %s || Rotation: %s"), *pvLocation.ToString(), *pvRotation.ToString());

		/// ray-cast maxDist to obj
		FVector lineTraceEnd = pvLocation + pvRotation.Vector() * maxReach;

		physicsHandle->SetTargetLocation(lineTraceEnd);
	}
}

/// PRIVATE FUNCTION DECLARATIONS *******************************************************************************************************************************************************

// Ray-cast and grab items in reach
void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("%s is Grabbing"), *(GetOwner()->GetName()));

	auto hitResult = GetFirstPhsyicsBodyInReach();
	UPrimitiveComponent* componentToGrab = hitResult.GetComponent();
	auto actorHit = hitResult.GetActor();

	if (actorHit) {
		physicsHandle->GrabComponent(componentToGrab, NAME_None, componentToGrab->GetOwner()->GetActorLocation(), true);
	}	
}

// Released any grabbed item
void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("%s is Releasing"), *(GetOwner()->GetName()));

	physicsHandle->ReleaseComponent();
}

// Set (physicsHandle) variable
void UGrabber::SetPhysicsHandleComponent() {
	physicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (physicsHandle) {
		UE_LOG(LogTemp, Warning, TEXT("%s UPhysicsHandleComponent found"), *(GetOwner()->GetName()));
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s missing UPhysicsHandleComponent"), *(GetOwner()->GetName()));
	}
}

// Set (inputComponent) variable
void UGrabber::SetInputComponent() {
	inputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (inputComponent) {
		UE_LOG(LogTemp, Warning, TEXT("%s UInputComponent found"), *(GetOwner()->GetName()));

		/// Bind input Axis
		inputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		inputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("%s missing UInputComponent"), *(GetOwner()->GetName()));
	}
}

// Return hit for first physics body in reach
const FHitResult UGrabber::GetFirstPhsyicsBodyInReach() {
	FVector pvLocation;
	FRotator pvRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT pvLocation, OUT pvRotation);
	//UE_LOG(LogTemp, Warning, TEXT("Location: %s || Rotation: %s"), *pvLocation.ToString(), *pvRotation.ToString());

	/// ray-cast maxDist to obj
	FVector lineTraceEnd = pvLocation + pvRotation.Vector() * maxReach;
	//DrawDebugLine(GetWorld(), pvLocation, lineTraceEnd, debugLineColor, false, 0.0f, 0.0f, 10.0f);

	FHitResult hit;
	FCollisionQueryParams traceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(OUT hit, pvLocation, lineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), traceParameters);

	AActor* actorHit = hit.GetActor();

	if (actorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Line Trace Hit: %s"), *(actorHit->GetName()));
	}

	return hit;
}

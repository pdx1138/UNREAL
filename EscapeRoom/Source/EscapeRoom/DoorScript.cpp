// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "DoorScript.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UDoorScript::UDoorScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorScript::BeginPlay()
{
	Super::BeginPlay();

	owner = GetOwner();

	if (actorThatOpens == nullptr) {
		
		actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
}


// Called every frame
void UDoorScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (presurePlate == nullptr) {
		return;
	}

	if (presurePlate->IsOverlappingActor(actorThatOpens)) {
		OpenDoor();
		lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
		
	if (isOpen && (GetWorld()->GetTimeSeconds() - lastDoorOpenTime > doorCloseDelay)) {
		CloseDoor();
	}
}

void UDoorScript::OpenDoor() {
	isOpen = true;
	owner->SetActorRotation(FRotator(0.0f, openAngle, 0.0f));
}

void UDoorScript::CloseDoor() {
	isOpen = false;
	owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}
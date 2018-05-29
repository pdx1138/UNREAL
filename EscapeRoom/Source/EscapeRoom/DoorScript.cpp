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

	if (actorThatOpens == nullptr) {
		
		actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
}


// Called every frame
void UDoorScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (presurePlate != nullptr) {
		if (presurePlate->IsOverlappingActor(actorThatOpens)) {
			OpenDoor();
		}
		else {
			CloseDoor();
		}
	}
}

void UDoorScript::OpenDoor() {
	/*AActor* thisOwner = GetOwner();*/
	FRotator newVec = FRotator(0.0f, openAngle, 0.0f);
	GetOwner()->SetActorRotation(newVec);
}

void UDoorScript::CloseDoor() {
	/*AActor* thisOwner = GetOwner();*/
	FRotator newVec = FRotator(0.0f, 0.0f, 0.0f);
	GetOwner()->SetActorRotation(newVec);
}
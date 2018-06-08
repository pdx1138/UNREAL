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

	if (pressurePlate.Num() == 0) {
		UE_LOG(LogTemp, Error, TEXT("%s needs a pressure plate assigned"), *(GetOwner()->GetName()));
	}
}


// Called every frame
void UDoorScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (pressurePlate.Num() == 0) {
		return;
	}

	/*if (pressurePlate->IsOverlappingActor(actorThatOpens)) {
		OpenDoor();
	}
	else*/
	if (GetTotalMassOfActorsOnPlate() > 65.0f) {
		OpenDoor();
	}
		
	if (isOpen && (GetWorld()->GetTimeSeconds() - lastDoorOpenTime > doorCloseDelay)) {
		CloseDoor();
	}
}

void UDoorScript::OpenDoor() {
	isOpen = true;
	/*owner->SetActorRotation(FRotator(0.0f, openAngle, 0.0f));*/
	lastDoorOpenTime = GetWorld()->GetTimeSeconds();
	OnOpenRequest.Broadcast();
}

void UDoorScript::CloseDoor() {
	isOpen = false;
	owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}

float UDoorScript::GetTotalMassOfActorsOnPlate() {
	float totalMass = 0.0f;

	if (pressurePlate.Num() == 0) { return 0.0f; }

	// Find all the overlapping actors
	/*TArray<AActor*> overlappingActors;*/
	for (const auto* pp : pressurePlate) {
		TArray<AActor*> overlappingActors;
		pp->GetOverlappingActors(OUT overlappingActors);

		// Iterate through them and add their mass
		for (const auto* actor : overlappingActors) {
			float tempMass = actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
			UE_LOG(LogTemp, Warning, TEXT("Calculating Mass of Object %s: %f"), *(actor->GetName()), tempMass);
			/*totalMass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();*/
			totalMass += tempMass;
		}
	}
	//pressurePlate->GetOverlappingActors(OUT overlappingActors);

	//// Iterate through them and add their mass
	//for (const auto* actor : overlappingActors) {
	//	UE_LOG(LogTemp, Warning, TEXT("Calculating Mass of Object %s"), *(actor->GetName()));
	//	totalMass += actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	//}

	//UE_LOG(LogTemp, Warning, TEXT("Total Mass of all Objects %f"), totalMass);
	return totalMass;
}

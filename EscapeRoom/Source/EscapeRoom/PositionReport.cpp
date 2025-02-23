// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PositionReport.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	AActor* thisOwner = GetOwner();
	FString objName = thisOwner->GetName();
	FString objPos = thisOwner->GetTransform().GetLocation().ToString();
//	FString objPos = "Coming Soon!";// thisOwner->GetActorTransform().TransformPosition.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s Reporting Position: %s"), *objName, *objPos);
	
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


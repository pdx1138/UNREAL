// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();

	AActor* myActor = GetOwner();
	FString objectName = myActor->GetName();
	FString objectPos = myActor->GetTransform().GetLocation().ToString();
	FString objectPosTwo = myActor->GetActorLocation().ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s is at %s & %s"), *objectName, *objectPos, *objectPosTwo);
}


// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


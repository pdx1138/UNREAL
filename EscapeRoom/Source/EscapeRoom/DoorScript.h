// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "DoorScript.generated.h"

#define OUT

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UDoorScript : public UActorComponent
{
	GENERATED_BODY()

	public:	
		// Sets default values for this component's properties
		UDoorScript();

		UPROPERTY(BlueprintAssignable)
		FDoorEvent OnOpen;

		UPROPERTY(BlueprintAssignable)
		FDoorEvent OnClose;

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	private:
		UPROPERTY(EditAnywhere)
		TArray<ATriggerVolume*> pressurePlate;

		UPROPERTY(EditAnywhere)
		AActor* actorThatOpens = nullptr;

		UPROPERTY(EditAnywhere)
		float triggerMass = 65.0f;

		AActor* owner;

		float GetTotalMassOfActorsOnPlate();
};

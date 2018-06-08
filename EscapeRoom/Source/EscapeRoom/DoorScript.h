// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "DoorScript.generated.h"

#define OUT

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UDoorScript : public UActorComponent
{
	GENERATED_BODY()

	public:	
		// Sets default values for this component's properties
		UDoorScript();
		void OpenDoor();
		void CloseDoor();

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	private:
		UPROPERTY(VisibleAnywhere)
		float openAngle = 90.0f;

		UPROPERTY(EditAnywhere)
		TArray<ATriggerVolume*> pressurePlate;

		UPROPERTY(EditAnywhere)
		AActor* actorThatOpens = nullptr;

		UPROPERTY(EditAnywhere)
		float doorCloseDelay = 1.0f;

		UPROPERTY(EditAnywhere)
		float lastDoorOpenTime = 0.0f;

		UPROPERTY(VisibleAnywhere)
		bool isOpen;

		AActor* owner;

		float GetTotalMassOfActorsOnPlate();
};

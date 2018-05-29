// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "DoorScript.generated.h"


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
		float openAngle = 70.0f;

		UPROPERTY(EditAnywhere)
		ATriggerVolume* presurePlate;

		UPROPERTY(EditAnywhere)
		AActor* actorThatOpens;

		UPROPERTY(EditAnywhere)
		float doorCloseDelay = 1.0f;

		UPROPERTY(EditAnywhere)
		float lastDoorOpenTime;

		UPROPERTY(VisibleAnywhere)
		bool isOpen;

		AActor* owner;		
};

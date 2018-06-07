// // Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

#define OUT

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

	public:	
		// Sets default values for this component's properties
		UGrabber();

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;

	public:	
		// Called every frame
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	private:		
		UPROPERTY(EditAnywhere)
		float maxReach = 100.0f;
		
		UPROPERTY(EditAnywhere)
		FColor debugLineColor = FColor(255.0f, 0.0f, 0.0f);
		
		UPhysicsHandleComponent* physicsHandle = nullptr;
		UInputComponent* inputComponent = nullptr;

		// Ray-cast and grab items in reach
		void Grab();

		// Released any grabbed item
		void Release();

		// Set (physicsHandle) variable
		void SetPhysicsHandleComponent();

		// Set (inputComponent) variable
		void SetInputComponent();

		// Return hit for first physics body in reach
		const FHitResult GetFirstPhsyicsBodyInReach();

		// Get the start of our reach
		FVector GetLineTraceStart();

		// Get the end of our reach
		FVector GetLineTraceEnd();
};

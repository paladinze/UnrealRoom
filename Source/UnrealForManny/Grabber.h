// Copyright Paladinze

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALFORMANNY_API UGrabber : public UActorComponent
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
	float Reach = 100.f;
	
	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputHandle = nullptr;

	// Ray cast and grab what's in reach
	void Grab();
	void GrabReleased();

	// Get physics handle
	void GetPhysicsHandle();

	// Setup attached input component
	void SetInputHandle();

	// Get the first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Get line trace info
	FVector GetLineTraceStart();
	FVector GetLineTraceEnd();
};

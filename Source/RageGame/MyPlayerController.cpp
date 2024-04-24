// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"


AMyPlayerController::AMyPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	JumpThreshold = 300.0f;

}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CalculateCanJump();

}

void AMyPlayerController::CalculateCanJump()
{

	UPrimitiveComponent* PrimitiveComponent = pCharacter->GetMesh();

	FVector LinearVelocity = PrimitiveComponent->GetPhysicsLinearVelocityAtPoint(FVector::ZeroVector);

	float VelocityLengthXY = LinearVelocity.Size2D();

	bCanJump = (VelocityLengthXY < JumpThreshold);
}

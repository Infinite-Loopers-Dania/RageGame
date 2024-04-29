// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFrameWork/Character.h"
#include "Components/PrimitiveComponent.h"
#include "UseInterface.h"
#include "MyPlayerController.generated.h"

/**
 *
 */
UCLASS()
class RAGEGAME_API AMyPlayerController : public APlayerController, public IUseInterface
{
	GENERATED_BODY()

public:
	AMyPlayerController();

	virtual void Tick(float DeltaTime) override;

	virtual void Use_Implementation() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	bool bCanJump;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Player")
	float JumpThreshold;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Player")
	ACharacter* pCharacter;

	UFUNCTION(BlueprintCallable)
	void CalculateCanJump();

};


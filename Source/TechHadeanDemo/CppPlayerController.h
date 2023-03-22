// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CppPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TECHHADEANDEMO_API ACppPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

private:
/*
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> HUDClass;


	UPROPERTY(EditAnywhere)
		UUserWidget* HUD;
		*/
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppUserWidget.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "cppHUD.generated.h"

/**
 * 
 */
UCLASS()
class TECHHADEANDEMO_API AcppHUD : public AHUD
{
	GENERATED_BODY()

public:
	AcppHUD();
	virtual void DrawHUD() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION()
		void SetPlayerID(int32 pHadeanPlayerID, int32 pUnRealPlayerId);
	UFUNCTION()
		void SetConnectInfo(int32 pConnectInstance, int32 pUnRealServer);

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		TSubclassOf<class UCppUserWidget> HUDClass;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
		UCppUserWidget* HUD;
};

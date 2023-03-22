// Fill out your copyright notice in the Description page of Project Settings.

#include "cppHUD.h"

AcppHUD::AcppHUD()
{
}

void AcppHUD::DrawHUD()
{
	Super::DrawHUD();
}




void AcppHUD::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AcppHUD: BeginPlay display HUD Start "));

	if (!HasAuthority() && HUDClass) {
		HUD = CreateWidget<UCppUserWidget>(GetWorld(), HUDClass);
		if (HUD) {
			UE_LOG(LogTemp, Warning, TEXT("AcppHUD: BeginPlay All Checked "));
			HUD->AddToViewport();
			HUD->SetPlayerID(0, 1);
			HUD->SetConnectInfo(1, 2);
		}
	}
}

void AcppHUD::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AcppHUD::SetPlayerID(int32 pHadeanPlayerID, int32 pUnRealPlayerId)
{
	UE_LOG(LogTemp, Warning, TEXT("AcppHUD: SetPlayerID START "));
	if (HUD) {
		HUD->SetPlayerID(pHadeanPlayerID, pUnRealPlayerId);
	}
}

void AcppHUD::SetConnectInfo(int32 pConnectInstance, int32 pUnRealServer)
{
	if (HUD) {
		HUD->SetConnectInfo(pConnectInstance, pUnRealServer);
	}
}

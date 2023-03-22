// Fill out your copyright notice in the Description page of Project Settings.


#include "CppPlayerController.h"


void ACppPlayerController::BeginPlay()
{
	Super::BeginPlay();

	/*
		UE_LOG(LogTemp, Warning, TEXT("CppCharacter: BeginPlay display HUD Start "));
		HUD = CreateWidget(this, HUDClass);
		check(HUD);
		UE_LOG(LogTemp, Warning, TEXT("CppCharacter: BeginPlay All Checked "));

		HUD->AddToPlayerScreen();
		//HUDUserWidget->AddToPlayerScreen();

		//HUDUserWidget->SetPlayerID(0, 1);
		//HUDUserWidget->SetConnectInfo(1, 2);
		*/


}

void ACppPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
}

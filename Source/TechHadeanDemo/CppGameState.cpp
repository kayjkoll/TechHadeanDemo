// Fill out your copyright notice in the Description page of Project Settings.


#include "CppGameState.h"

ACppGameState::ACppGameState() {
	//UE_LOG(LogTemp, Warning, TEXT("ACppGameState´: Instantiated"));
}

void ACppGameState::SetSyncVariable(int32 pValue)
{
	SyncIntValue = pValue;
}

int32 ACppGameState::GetSyncVariable()
{
	return SyncIntValue;
}
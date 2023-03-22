// Fill out your copyright notice in the Description page of Project Settings.


#include "CppPlayerState.h"

void ACppPlayerState::SetHadeanPlayerID(int32 PlayerID)
{
	HadeanPlayerID = PlayerID;
}

int32 ACppPlayerState::GetHadeanPlayerID()
{
	return HadeanPlayerID;
}

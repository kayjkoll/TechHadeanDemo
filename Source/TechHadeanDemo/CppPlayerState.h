// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CppPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class TECHHADEANDEMO_API ACppPlayerState : public APlayerState
{
	GENERATED_BODY()

private:
	int32 HadeanPlayerID;
	
public:
	void SetHadeanPlayerID(int32 PlayerID);

	int32 GetHadeanPlayerID();
};

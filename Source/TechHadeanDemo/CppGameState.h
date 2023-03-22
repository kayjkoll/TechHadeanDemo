// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CppGameState.generated.h"

/**
 * 
 */
UCLASS()
class TECHHADEANDEMO_API ACppGameState : public AGameStateBase
{
	GENERATED_BODY()

private:
	uint32 SyncIntValue = 0;

public:
	ACppGameState();

	void SetSyncVariable(int32 pValue);

	int32 GetSyncVariable();
	
};

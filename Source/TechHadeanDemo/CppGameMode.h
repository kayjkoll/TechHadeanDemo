// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CppGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TECHHADEANDEMO_API ACppGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACppGameMode();

protected:
	int32 getTotalNumberUsers();

};

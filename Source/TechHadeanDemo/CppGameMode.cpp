// Fill out your copyright notice in the Description page of Project Settings.


#include "CppGameMode.h"
#include "CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACppGameMode::ACppGameMode() : Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/TechHadeanDemo/BP_CharacterBlueprint"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACppGameMode::StaticClass();
}

int32 ACppGameMode::getTotalNumberUsers()
{
	return int32();
}

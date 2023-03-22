// Fill out your copyright notice in the Description page of Project Settings.


#include "CppCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "CppGameMode.h"
#include "CppGameState.h"
#include "CppPlayerState.h"
#include "CppUserWidget.h"
#include "cppHUD.h"
#include "CppPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "XRMotionControllerBase.h" // for FXRMotionControllerBase::RightHandSourceId
#include "Net/UnrealNetwork.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

// Sets default values
ACppCharacter::ACppCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;
	/*
	// Create a CameraComponent	
	CharacterCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CharacterCamera"));
	CharacterCameraComponent->SetupAttachment(GetCapsuleComponent());
	CharacterCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	CharacterCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh0 = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh0"));
	Mesh0->SetOnlyOwnerSee(true);
	Mesh0->SetupAttachment(CharacterCameraComponent);
	Mesh0->bCastDynamicShadow = false;
	Mesh0->CastShadow = false;
	Mesh0->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh0->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
	*/


}

// Called when the game starts or when spawned
void ACppCharacter::BeginPlay()
{
	Super::BeginPlay();

	/*
	if (IsLocallyControlled() && HUDClass) {
		UE_LOG(LogTemp, Warning, TEXT("CppCharacter: BeginPlay display HUD Start "));
		APlayerController* FPC = GetController<APlayerController>();
		check(FPC);
		HUD = CreateWidget<UCppUserWidget>(FPC, HUDClass);
		check(HUD);
		UE_LOG(LogTemp, Warning, TEXT("CppCharacter: BeginPlay All Checked "));
		

		HUD->AddToPlayerScreen();
		//HUD->AddToViewport();
		HUD->SetPlayerID(0, 1);
		//HUD->SetConnectInfo(1, 2);		

		FPC->SetActorHiddenInGame(false);
	}
	*/
}

void ACppCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
/*
	if (HUD) {
	//	HUD->RemoveFromParent();
		// We can't destroy the widget directly, let the GC take care of it
//		HUD = nullptr;
	}
	*/
	Super::EndPlay(EndPlayReason);
}

// Called every frame
void ACppCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACppCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("UpdateHUD", IE_Pressed, this, &ACppCharacter::UpdateHUD);

	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &ACppCharacter::MovePerson);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACppCharacter::TurnPerson);
	PlayerInputComponent->BindAxis("Turn", this, &ACppCharacter::LookLeftRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACppCharacter::LookupDown);

	

	actorCount = GetWorld()->GetActorCount();
	UE_LOG(LogTemp, Warning, TEXT("*****SetupPlayerInputComponent - ActorCount %d: "), actorCount);
		
	if (HasAuthority()) {
		if (ACppGameMode* GM = GetWorld()->GetAuthGameMode<ACppGameMode>()) {
			UE_LOG(LogTemp, Warning, TEXT("ACppGameMode´: GM from CppCharacter "));
		}

		if (ACppGameState* GS = GetWorld()->GetGameState<ACppGameState>()) {
			UE_LOG(LogTemp, Warning, TEXT("ACppGameState´: GS from CppCharacter "));
			//
			//;
		}
		
		if (ACppPlayerState* PS = GetPlayerState<ACppPlayerState>()) {			
			int32 UEPlayerID = PS->GetPlayerId();
			UE_LOG(LogTemp, Warning, TEXT("ACppPlayerState´: PS from CppCharacter UEPlayerID: %d, HadeanPlayerID"), UEPlayerID);
		}
				
	}
}

void ACppCharacter::MovePerson(float Value)
{
	if (Value != 0.0f)
	{
		//UE_LOG(LogTemp, Warning, TEXT("***MovePerson: %d - Value: %f"), actorCount, Value);
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ACppCharacter::TurnPerson(float Value)
{
	if (Value != 0.0f)
	{
		//UE_LOG(LogTemp, Warning, TEXT("***TurnPerson: %d - Value: %f"), actorCount, Value);
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);				
	}	
}

void ACppCharacter::LookupDown(float AxisValue)
{
	if (AxisValue != 0.0f) {
		AddControllerPitchInput(AxisValue);
	}
}

void ACppCharacter::LookLeftRight(float AxisValue)
{
	if (AxisValue != 0.0f) {
		AddControllerYawInput(AxisValue);
	}
}

void ACppCharacter::UpdateHUD()
{

	UE_LOG(LogTemp, Warning, TEXT("CppCharacter::UpdateHUD !!"));
	AcppHUD* cppHUD = Cast<AcppHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if (cppHUD) {
		cppHUD->SetConnectInfo(++HadeanConnectID, ++UnRealServerID);
	}
	
}


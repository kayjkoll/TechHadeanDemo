// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CppCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UMotionControllerComponent;
class UAnimMontage;
class USoundBase;

UCLASS()
class TECHHADEANDEMO_API ACppCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* Mesh0;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CharacterCameraComponent;

public:
	// Sets default values for this character's properties
	ACppCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	// Similar to a Handean's Player ID
	int32 actorCount = 0;

	int32 HadeanConnectID = 0;
	int32 UnRealServerID = 0;

protected:
	//void Interact();
		
	//UFUNCTION(NetMulticast, Reliable, WithValidation)
	/** Handles moving forward/backward */
	void MovePerson(float AxisValue);

	/** Handles stafing movement, left and right */
	void TurnPerson(float AxisValue);

	void LookupDown(float AxisValue);
	void LookLeftRight(float AxisValue);
	void UpdateHUD();
	
public:
	/** Returns Mesh0 subobject **/
	USkeletalMeshComponent* GetMesh0() const { return Mesh0; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetCharacterCameraComponent() const { return CharacterCameraComponent; }
	/*
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UCppUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
		UCppUserWidget* HUD;

	*/
};
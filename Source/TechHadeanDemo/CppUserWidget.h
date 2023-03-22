// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "CppUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TECHHADEANDEMO_API UCppUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCppUserWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = Hadean)
	void SetPlayerID(int32 pHadeanPlayerID, int32 pUnRealPlayerId);

	UFUNCTION(BlueprintCallable, Category = Hadean)
	void SetConnectInfo(int32 pConnectInstance, int32 pUnRealServer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* PlayerIDTextBlock;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* ConnectTextBlock;

private:


};

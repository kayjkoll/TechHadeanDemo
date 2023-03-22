// Fill out your copyright notice in the Description page of Project Settings.


#include "CppUserWidget.h"
#include "Components/TextBlock.h"


UCppUserWidget::UCppUserWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UCppUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UCppUserWidget::SetPlayerID(int32 pHadeanPlayerID, int32 pUnRealPlayerID)
{

	UE_LOG(LogTemp, Warning, TEXT("CppUserWidget: BEGIN: Set PlayerID "));
	if (PlayerIDTextBlock) {
		if (PlayerIDTextBlock->GetVisibility() == ESlateVisibility::Hidden) {
			PlayerIDTextBlock->SetVisibility(ESlateVisibility::Visible);
		}
		UE_LOG(LogTemp, Warning, TEXT("CppUserWidget: SETTEXT: Set PlayerID "));
		PlayerIDTextBlock->SetText(FText::FromString(FString(TEXT("Hadean PlayerID: "))
			.Append(FString::FromInt(pHadeanPlayerID))
			.Append(FString(TEXT("  UnReal ID: ")))
			.Append(FString::FromInt(pUnRealPlayerID))));			
	}
}

void UCppUserWidget::SetConnectInfo(int32 pConnectInstance, int32 pUnRealServer)
{
	if (ConnectTextBlock) {
		if (ConnectTextBlock->GetVisibility() == ESlateVisibility::Hidden) {
			ConnectTextBlock->SetVisibility(ESlateVisibility::Visible);
		}
		ConnectTextBlock->SetText(FText::FromString(FString(TEXT("Hadean Connect : "))
			.Append(FString::FromInt(pConnectInstance))
			.Append(FString(TEXT("  UnReal Srv Id: ")))
			.Append(FString::FromInt(pUnRealServer))));
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ChooseCharacter_Activatable.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UChooseCharacter_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UChooseCharacter_Activatable();

protected:
	void NativeOnInitialized() override;
	void NativePreConstruct() override;
	void NativeConstruct() override;
	FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;

	bool NativeOnHandleBackAction() override;

private:
	UFUNCTION()
	void OnDeleteCharacter(UObject* ListItem);

	UPROPERTY(meta = (BindWidget))
	class UMyListViewBase* ListView;
};

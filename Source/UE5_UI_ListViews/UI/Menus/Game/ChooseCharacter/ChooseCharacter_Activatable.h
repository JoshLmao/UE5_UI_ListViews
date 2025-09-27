// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ChooseCharacter_Activatable.generated.h"

/**
 * Method 1: The most basic and common to use a ListView.
 * 
 * Populate a UCLASS object with static data once at start.
 * Handles removing specific elements and adding new elements to end.
 * Able to handle elements with buttons to trigger actions, like Delete
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
	void OnCreateNewCharacter();
	UCharacterListItem* CreateListItem(int ElementIndex);

	UFUNCTION()
	void OnDeleteCharacter(UObject* ListItem);

	UPROPERTY(meta = (BindWidget))
	class UMyListViewBase* ListView;

	UPROPERTY(meta = (BindWidget))
	class UTextButton* CreateCharacterButton;
};

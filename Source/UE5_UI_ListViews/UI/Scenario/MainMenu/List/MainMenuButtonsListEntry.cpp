// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuButtonsListEntry.h"

#include "MainMenuListItem.h"
#include "UE5_UI_ListViews/UI/Common/Button/TextButton.h"

void UMainMenuButtonsListEntry::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Button->OnClicked().AddUObject(this, &ThisClass::OnEntryButtonClicked);
}

void UMainMenuButtonsListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto* ExpectedListItem = Cast<UMainMenuListItem>(ListItemObject);
	if (!IsValid(ExpectedListItem))
	{
		return;
	}

	MainMenuListItem = ExpectedListItem;

	Button->SetText(MainMenuListItem->Text);
}

void UMainMenuButtonsListEntry::OnEntryButtonClicked() const
{
	UE_LOG(LogTemp, Log, TEXT("%s entry clicked"), *GetName());
	if (IsValid(MainMenuListItem))
	{
		MainMenuListItem->ListItemClickedDelegate.ExecuteIfBound(MainMenuListItem);
	}
}
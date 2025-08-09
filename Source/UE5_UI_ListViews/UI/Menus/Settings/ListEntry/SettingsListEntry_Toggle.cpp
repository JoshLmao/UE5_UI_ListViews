// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsListEntry_Toggle.h"

#include "CommonTextBlock.h"
#include "Components/Button.h"
#include "UE5_UI_ListViews/UI/Menus/Settings/ListItem/SettingsListItem_Toggle.h"

void USettingsListEntry_Toggle::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ToggleButton->OnClicked.AddDynamic(this, &ThisClass::OnToggleButtonClicked);
}

void USettingsListEntry_Toggle::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto* ToggleData = Cast<USettingsListItem_Toggle>(ListItemObject);
	if (!IsValid(ToggleData))
	{
		return;
	}

	SetStatus(ToggleData->GetToggleStatus());
}

UWidget* USettingsListEntry_Toggle::Settings_GetFocusTarget()
{
	return ToggleButton;
}

void USettingsListEntry_Toggle::OnToggleButtonClicked()
{
	SetStatus(!CurrentStatus);
}

void USettingsListEntry_Toggle::SetStatus(const bool InStatus)
{
	CurrentStatus = InStatus;
	StatusTextBlock->SetText(InStatus ? FText::FromString("Enabled") : FText::FromString("Disabled"));
}

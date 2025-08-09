// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsListEntry_Carousel.h"

#include "CommonRotator.h"
#include "Components/Button.h"
#include "UE5_UI_ListViews/UI/Scenario/Settings/ListItem/SettingsListItem_Carousel.h"

void USettingsListEntry_Carousel::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	LeftButton->OnClicked.AddUniqueDynamic(this, &USettingsListEntry_Carousel::OnLeftButtonClicked);
	RightButton->OnClicked.AddUniqueDynamic(this, &USettingsListEntry_Carousel::OnRightButtonClicked);
}

void USettingsListEntry_Carousel::NativePreConstruct()
{
	Super::NativePreConstruct();

	// Set initial opacity for OnHover animation starting value
	SetColorAndOpacity(FLinearColor(1.f, 1.f, 1.f, 0.5f));
}

void USettingsListEntry_Carousel::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto* CarouselData = Cast<USettingsListItem_Carousel>(ListItemObject);
	if (!IsValid(CarouselData))
	{
		return;
	}

	auto AllOptions = CarouselData->GetOptions();
	Rotator->PopulateTextLabels(AllOptions);
	Rotator->SetSelectedItem(0);
}

UWidget* USettingsListEntry_Carousel::Settings_GetFocusTarget()
{
	return Rotator;
}

void USettingsListEntry_Carousel::OnLeftButtonClicked()
{
	Rotator->ShiftTextLeft();
}

void USettingsListEntry_Carousel::OnRightButtonClicked()
{
	Rotator->ShiftTextRight();
}
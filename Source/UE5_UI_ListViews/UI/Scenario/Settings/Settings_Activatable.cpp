// Fill out your copyright notice in the Description page of Project Settings.

#include "Settings_Activatable.h"

#include "Registry/SettingsRegistry.h"
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"
#include "UE5_UI_ListViews/UI/Common/Button/TextButton.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

USettings_Activatable::USettings_Activatable()
{
	SetIsFocusable(true);
}

void USettings_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	BackButton->OnClicked().AddUObject(this, &ThisClass::OnButtonBackClicked);
}

void USettings_Activatable::NativeConstruct()
{
	Super::NativeConstruct();

	const TArray<UObject*> AllData = USettingsRegistry::BuildSettings();
	ListView->SetListItems(AllData);
}

UWidget* USettings_Activatable::NativeGetDesiredFocusTarget() const
{
	return ListView;
}

void USettings_Activatable::OnButtonBackClicked() const
{
	auto* HUDControl = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	HUDControl->OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));
}
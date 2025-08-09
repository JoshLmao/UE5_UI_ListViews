// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu_Activatable.h"

#include "GameplayTagContainer.h"
#include "List/MainMenuListItem.h"
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

UMainMenu_Activatable::UMainMenu_Activatable()
{
	SetIsFocusable(true);
}

void UMainMenu_Activatable::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UObject*> AllData;
	AllData.Add(UMainMenuListItem::MakeListItem(this, FText::FromString("Play"), this, GET_FUNCTION_NAME_CHECKED(UMainMenu_Activatable, OnPlayClicked)));
	AllData.Add(UMainMenuListItem::MakeListItem(this, FText::FromString("Matchmake"), this, GET_FUNCTION_NAME_CHECKED(UMainMenu_Activatable, OnMatchmakeClicked)));
	AllData.Add(UMainMenuListItem::MakeListItem(this, FText::FromString("Settings"), this, GET_FUNCTION_NAME_CHECKED(UMainMenu_Activatable, OnSettingsClicked)));
	AllData.Add(UMainMenuListItem::MakeListItem(this, FText::FromString("Quit to Desktop"), this, GET_FUNCTION_NAME_CHECKED(UMainMenu_Activatable, OnQuitToDesktop)));

	ListView->SetListItems(AllData);
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return ListView;
}

void UMainMenu_Activatable::OnPlayClicked(const UObject* Item)
{
	UE_LOG(LogTemp, Log, TEXT("OnPlayClicked"));
}

void UMainMenu_Activatable::OnMatchmakeClicked(const UObject* Item)
{
	UE_LOG(LogTemp, Log, TEXT("OnMatchmakeClicked"));

	auto* HUD = Cast<AMainMenuHUD>(GetPlayerContext().GetPlayerController()->GetHUD());
	HUD->OpenWidget(FGameplayTag::RequestGameplayTag(FName("UI.MainMenu.Matchmake")));
}

void UMainMenu_Activatable::OnSettingsClicked(const UObject* Item)
{
	UE_LOG(LogTemp, Log, TEXT("OnSettingsClicked"));

	auto* HUD = Cast<AMainMenuHUD>(GetPlayerContext().GetPlayerController()->GetHUD());
	HUD->OpenWidget(FGameplayTag::RequestGameplayTag(FName("UI.MainMenu.Settings")));
}

void UMainMenu_Activatable::OnQuitToDesktop(const UObject* Item)
{
	UE_LOG(LogTemp, Log, TEXT("OnQuitToDesktop"));
}
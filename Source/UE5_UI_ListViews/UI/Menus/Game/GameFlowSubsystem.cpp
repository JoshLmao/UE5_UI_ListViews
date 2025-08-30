// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFlowSubsystem.h"

#include "GameplayTagContainer.h"
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"

void UGameFlowSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	GameWidgetOrder.Add(FGameplayTag::RequestGameplayTag("UI.Game.ChooseCharacter"));
	GameWidgetOrder.Add(FGameplayTag::RequestGameplayTag("UI.Game.ChooseCharacter")); // TODO: Make new game and replace. Have two games for testing

	CurrentGameWidgetIndex = 0;
}

void UGameFlowSubsystem::StartGame()
{
	CurrentGameWidgetIndex = 0;
	ShowGame(CurrentGameWidgetIndex);
}

void UGameFlowSubsystem::NextGame()
{
	CurrentGameWidgetIndex++;
	ShowGame(CurrentGameWidgetIndex);
}

void UGameFlowSubsystem::PreviousGame()
{
	CurrentGameWidgetIndex--;
	ShowGame(CurrentGameWidgetIndex);
}

void UGameFlowSubsystem::ShowGame(int32 GameWidgetIndex)
{
	if (GameWidgetIndex >= GameWidgetOrder.Num())
	{
		EndGames();
		return;
	}

	if (GameWidgetIndex < 0)
	{
		// Do nothing.
		return;
	}

	ShowUI(GameWidgetOrder[GameWidgetIndex]);
}

void UGameFlowSubsystem::ShowUI(const FGameplayTag& WidgetTag)
{
	const auto* FirstPlayer = GetWorld()->GetFirstPlayerController();
	auto* HUD = Cast<AMainMenuHUD>(FirstPlayer->GetHUD());
	HUD->OpenWidget(WidgetTag);
}

void UGameFlowSubsystem::EndGames()
{
	ShowUI(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));
}
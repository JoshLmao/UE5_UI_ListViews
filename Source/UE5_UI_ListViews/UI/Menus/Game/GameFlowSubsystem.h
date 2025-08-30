// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayTagContainer.h"
#include "GameFlowSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UGameFlowSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;

	// Starts the list view games at the first game
	void StartGame();
	// Ends the list view games and returns to main menu
	void EndGames();

	// Moves to the next game, if possible
	void NextGame();
	// Moves to the previous game, if possible
	void PreviousGame();

private:
	// Updates UI to the given GameWidgetIndex
	void ShowGame(int32 GameWidgetIndex);
	void ShowUI(const struct FGameplayTag& WidgetTag);

	TArray<FGameplayTag> GameWidgetOrder;
	int32 CurrentGameWidgetIndex = 0;
};

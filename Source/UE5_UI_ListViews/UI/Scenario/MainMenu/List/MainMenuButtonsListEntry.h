// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListEntryBase.h"
#include "MainMenuButtonsListEntry.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UMainMenuButtonsListEntry : public UMyListEntryBase
{
	GENERATED_BODY()

protected:
	void NativeOnInitialized() override;
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;

private:
	void OnEntryButtonClicked() const;

	UPROPERTY(meta = (BindWidget))
	class UTextButton* Button;

	UPROPERTY()
	class UMainMenuListItem* MainMenuListItem;
};

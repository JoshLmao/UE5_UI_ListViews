// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsListEntryBase.h"
#include "SettingsListEntry_Toggle.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettingsListEntry_Toggle : public USettingsListEntryBase
{
	GENERATED_BODY()

protected:
	void NativeOnInitialized() override;
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UWidget* Settings_GetFocusTarget() override;

private:
	UFUNCTION()
	void OnToggleButtonClicked();

	void SetStatus(const bool InStatus);

	UPROPERTY()
	bool CurrentStatus;

	UPROPERTY(meta = (BindWidget))
	class UButton* ToggleButton;

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* StatusTextBlock;
};

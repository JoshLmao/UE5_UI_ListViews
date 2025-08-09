// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Scenario/Settings/ListEntry/SettingsListEntryBase.h"
#include "SettingsListEntry_Carousel.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API USettingsListEntry_Carousel : public USettingsListEntryBase
{
	GENERATED_BODY()

protected:
	void NativeOnInitialized() override;
	void NativePreConstruct() override;

	void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	UWidget* Settings_GetFocusTarget() override;

private:
	UFUNCTION()
	void OnLeftButtonClicked();
	UFUNCTION()
	void OnRightButtonClicked();

	UPROPERTY(meta = (BindWidget))
	class UButton* LeftButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* RightButton;

	UPROPERTY(meta = (BindWidget))
	class UCommonRotator* Rotator;
};

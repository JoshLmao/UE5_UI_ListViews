// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListEntryBase.h"
#include "SettingsListEntryBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API USettingsListEntryBase : public UMyListEntryBase
{
	GENERATED_BODY()

protected:
	void NativePreConstruct() override;

	void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	void NativeOnEntryReleased() override;

	FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;

	void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

	virtual UWidget* Settings_GetFocusTarget()
	{
		// each inheriting ListEntry should override and specify what to focus
		return nullptr;
	}

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* TitleTextBlock;

	UPROPERTY(Transient, meta = (BindWidgetAnimOptional))
	class UWidgetAnimation* Anim_OnHover;
};

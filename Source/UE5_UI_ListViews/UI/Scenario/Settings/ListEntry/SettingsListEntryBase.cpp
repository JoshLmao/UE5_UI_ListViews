// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsListEntryBase.h"

#include "CommonTextBlock.h"
#include "Animation/WidgetAnimation.h"
#include "UE5_UI_ListViews/UI/Scenario/Settings/ListItem/SettingsListItemBase.h"

void USettingsListEntryBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (IsDesignTime())
	{
		TitleTextBlock->SetText(FText::FromString("Example title"));
	}
}

void USettingsListEntryBase::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto* SettingsListEntryBase = Cast<USettingsListItemBase>(ListItemObject);
	if (!IsValid(SettingsListEntryBase))
	{
		return;
	}

	TitleTextBlock->SetText(SettingsListEntryBase->GetTitle());
}

void USettingsListEntryBase::NativeOnEntryReleased()
{
	Super::NativeOnEntryReleased();

	StopAllAnimations();
}

FReply USettingsListEntryBase::NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent)
{
	// Get child's UWidget to direct focus onto
	UWidget* UserWidgetToFocus = Settings_GetFocusTarget();
	if (IsValid(UserWidgetToFocus))
	{
		return FReply::Handled().SetUserFocus(UserWidgetToFocus->TakeWidget());
	}
	return FReply::Unhandled();
}

void USettingsListEntryBase::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	if (IsValid(Anim_OnHover))
	{
		PlayAnimation(Anim_OnHover);
	}
}

void USettingsListEntryBase::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	if (IsValid(Anim_OnHover))
	{
		PlayAnimation(Anim_OnHover);
	}
}
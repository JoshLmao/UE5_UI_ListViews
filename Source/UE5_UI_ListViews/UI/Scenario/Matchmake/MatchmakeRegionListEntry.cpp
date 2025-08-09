// Fill out your copyright notice in the Description page of Project Settings.

#include "MatchmakeRegionListEntry.h"

#include "CommonBorder.h"
#include "CommonTextBlock.h"
#include "Matchmake_Activatable.h"

UMatchmakeRegionListEntry::UMatchmakeRegionListEntry()
{
	Visibility = ESlateVisibility::Visible;
}

void UMatchmakeRegionListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto CastedListItem = Cast<USimpleListItem>(ListItemObject);
	if (!IsValid(CastedListItem))
	{
		return;
	}

	UpdateWidget(CastedListItem);
}

void UMatchmakeRegionListEntry::NativeOnItemSelectionChanged(bool bIsSelected)
{
	Super::NativeOnItemSelectionChanged(bIsSelected);
	UpdateBackgroundColor();
}

void UMatchmakeRegionListEntry::UpdateWidget(const USimpleListItem* ListItem)
{
	RegionTextBlock->SetText(ListItem->Text);
	UpdateBackgroundColor();
}

void UMatchmakeRegionListEntry::UpdateBackgroundColor() const
{
	RootBorder->SetBrushColor(IsListItemSelected() ? SelectedBackground : UnselectedBackground);
}

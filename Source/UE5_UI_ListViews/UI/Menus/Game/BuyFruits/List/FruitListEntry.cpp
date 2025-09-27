// Fill out your copyright notice in the Description page of Project Settings.

#include "FruitListEntry.h"

#include "CommonTextBlock.h"
#include "FruitListItem.h"
#include "UE5_UI_ListViews/UI/Menus/Game/BuyFruits/SupermarketDataSubsystem.h"

void UFruitListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto ExpectedListItem = Cast<UFruitListItem>(ListItemObject);
	if (!IsValid(ExpectedListItem))
	{
		return;
	}

	FruitID = ExpectedListItem->ID;
	UpdateWidget(FruitID);
}

void UFruitListEntry::UpdateWidget(const FName& ID) const
{
	FFruit FruitData;
	if (!USupermarketDataSubsystem::Get(GetWorld())->GetFruitFromID(ID, FruitData))
	{
		NameTextBlock->SetText(FText::FromString("Invalid ID: " + ID.ToString() + " doesn't exist in Data!"));
		IDTextBlock->SetText(FText::GetEmpty());
		return;
	}

	NameTextBlock->SetText(FruitData.Name);
	IDTextBlock->SetText(FText::FromName(ID));
}
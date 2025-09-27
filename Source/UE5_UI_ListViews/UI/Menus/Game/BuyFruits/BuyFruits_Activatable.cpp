// Fill out your copyright notice in the Description page of Project Settings.

#include "BuyFruits_Activatable.h"

#include "SupermarketDataSubsystem.h"
#include "List/FruitListItem.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

UBuyFruits_Activatable::UBuyFruits_Activatable()
{
	SetIsFocusable(true);
	bIsBackHandler = true;
	bIsBackActionDisplayedInActionBar = true;
}

void UBuyFruits_Activatable::NativeConstruct()
{
	Super::NativeConstruct();

	const auto DataSubsystem = USupermarketDataSubsystem::Get(GetWorld());
	const TArray<FName> AllIDs = DataSubsystem->GetAllFruitIDs();

	TArray<UFruitListItem*> ListItems;
	for (const auto& ID : AllIDs)
	{
		auto* ListItem = NewObject<UFruitListItem>(this);
		ListItem->ID = ID;
		ListItems.Add(ListItem);
	}
	ListView->SetListItems(ListItems);
}
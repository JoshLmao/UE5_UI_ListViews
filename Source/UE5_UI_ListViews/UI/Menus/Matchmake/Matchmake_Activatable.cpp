// Fill out your copyright notice in the Description page of Project Settings.

#include "Matchmake_Activatable.h"

#include "CommonTextBlock.h"
#include "GameplayTagContainer.h"
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"
#include "UE5_UI_ListViews/Setup/MyGameInstance.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

UMatchmake_Activatable::UMatchmake_Activatable()
{
	SetIsFocusable(true);
	bIsBackHandler = true;
	bIsBackActionDisplayedInActionBar = true;
}

void UMatchmake_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ListView->OnItemSelectionChanged().AddUObject(this, &ThisClass::OnListViewItemSelectionChanged);
}

void UMatchmake_Activatable::NativePreConstruct()
{
	Super::NativePreConstruct();

	TitleTextBlock->SetText(FText::FromString("Select Matchmaking Region"));
	ListView->SetSelectionMode(ESelectionMode::Type::Single);
}

void UMatchmake_Activatable::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UObject*> AllOptions;
	AllOptions.Add(USimpleListItem::Create(this, TEXT("euro"), FText::FromString("Europe")));
	AllOptions.Add(USimpleListItem::Create(this, TEXT("afr"), FText::FromString("Africa")));
	AllOptions.Add(USimpleListItem::Create(this, TEXT("na"), FText::FromString("North America")));
	AllOptions.Add(USimpleListItem::Create(this, TEXT("sa"), FText::FromString("South America")));
	AllOptions.Add(USimpleListItem::Create(this, TEXT("asia"), FText::FromString("Asia")));
	ListView->SetListItems(AllOptions);

	// Obtain data for the current selected region and make it selected and move focus to it
	FName CurrentRegion = Cast<UMyGameInstance>(GetGameInstance())->GetMatchmakeRegion();
	for (const auto ListItem : AllOptions)
	{
		const auto* SimpleListItem = Cast<USimpleListItem>(ListItem);
		if (SimpleListItem->Id.IsEqual(CurrentRegion))
		{
			ListView->RequestNavigateToItem(ListItem);
			ListView->SetSelectedItem(ListItem);
		}
	}
}

bool UMatchmake_Activatable::NativeOnHandleBackAction()
{
	auto* MenuHUD = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	MenuHUD->OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));

	return true; // handled close
}

FReply UMatchmake_Activatable::NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent)
{
	return FReply::Handled().SetUserFocus(ListView->TakeWidget());
}

void UMatchmake_Activatable::OnListViewItemSelectionChanged(UObject* ListItem)
{
	if (ListView->IsItemSelected(ListItem))
	{
		auto* SimpleListItem = Cast<USimpleListItem>(ListItem);
		if (!IsValid(SimpleListItem))
		{
			return;
		}

		Cast<UMyGameInstance>(GetGameInstance())->SetMatchmakeRegion(SimpleListItem->Id);
	}
}

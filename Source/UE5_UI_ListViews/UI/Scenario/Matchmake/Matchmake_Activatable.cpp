// Fill out your copyright notice in the Description page of Project Settings.

#include "Matchmake_Activatable.h"

#include "CommonTextBlock.h"
#include "GameplayTagContainer.h"
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

UMatchmake_Activatable::UMatchmake_Activatable()
{
	SetIsFocusable(true);
	bIsBackHandler = true;
	bIsBackActionDisplayedInActionBar = true;
}

void UMatchmake_Activatable::NativePreConstruct()
{
	Super::NativePreConstruct();

	TitleTextBlock->SetText(FText::FromString("Select Matchmaking Region"));

	ListView->SetSelectionMode(ESelectionMode::Type::Single);

	TArray<UObject*> AllOptions;
	AllOptions.Add(USimpleListItem::Create(this, FText::FromString("Europe")));
	AllOptions.Add(USimpleListItem::Create(this, FText::FromString("Africa")));
	AllOptions.Add(USimpleListItem::Create(this, FText::FromString("North America")));
	AllOptions.Add(USimpleListItem::Create(this, FText::FromString("South America")));
	AllOptions.Add(USimpleListItem::Create(this, FText::FromString("Asia")));
	ListView->SetListItems(AllOptions);
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

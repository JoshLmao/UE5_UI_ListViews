// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseCharacter_Activatable.h"

#include "List/CharacterListItem.h"

#include <GameplayTagContainer.h>
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

UChooseCharacter_Activatable::UChooseCharacter_Activatable()
{
	SetIsFocusable(true);
	bIsBackHandler = true;
	bIsBackActionDisplayedInActionBar = true;
}

void UChooseCharacter_Activatable::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UChooseCharacter_Activatable::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UObject*> AllData;
	for (int i = 0; i < 20; i++)
	{
		FName Id = FName(*FString::Printf(TEXT("random-id-%d"), i));
		FText CharName = FText::Format(FText::FromString(TEXT("{0}{1}")), FText::FromString("Character "), FText::AsNumber(i));
		AllData.Add(UCharacterListItem::Create(this, Id, CharName));
	}
	ListView->SetListItems(AllData);
}

FReply UChooseCharacter_Activatable::NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent)
{
	return FReply::Handled().SetUserFocus(ListView->TakeWidget());
}

bool UChooseCharacter_Activatable::NativeOnHandleBackAction()
{
	// TODO: implement dialog confirming if you wish to exit game
	// for now, just always exit
	auto* HUDControl = Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD());
	HUDControl->OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));
	return true;
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseCharacter_Activatable.h"

#include "List/CharacterListItem.h"

#include <GameplayTagContainer.h>
#include "UE5_UI_ListViews/Setup/MainMenuHUD.h"
#include "UE5_UI_ListViews/UI/Common/Button/TextButton.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListViewBase.h"

UChooseCharacter_Activatable::UChooseCharacter_Activatable()
{
	SetIsFocusable(true);
	bIsBackHandler = true;
	bIsBackActionDisplayedInActionBar = true;
}

void UChooseCharacter_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	CreateCharacterButton->OnClicked().AddUObject(this, &ThisClass::OnCreateNewCharacter);
}

void UChooseCharacter_Activatable::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UChooseCharacter_Activatable::NativeConstruct()
{
	Super::NativeConstruct();

	TArray<UObject*> AllData;
	for (double i = 0; i < 20; i++)
	{
		const FName Id = FName(*FString::Printf(TEXT("random-id-%d"), i));
		const FText Name = FText::Format(FText::FromString(TEXT("{0}{1}")), FText::FromString("Character "), FText::AsNumber(i));
		const int32 Level = FMath::Abs(FMath::Sin(i) * 100); // Some random number
		auto* ListItem = UCharacterListItem::Create(this, Id, Name, Level);
		ListItem->OnDeleteCharacter.BindUObject(this, &ThisClass::OnDeleteCharacter);
		AllData.Add(ListItem);
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

void UChooseCharacter_Activatable::OnCreateNewCharacter()
{
	const int32 EntryIndex = ListView->GetNumItems();
	const FName Id = FName(*FString::Printf(TEXT("random-id-%d"), EntryIndex));
	const FText Name = FText::Format(FText::FromString(TEXT("{0}{1}")), FText::FromString("Character "), FText::AsNumber(EntryIndex));

	// Create and add to ListView
	auto* ListItem = UCharacterListItem::Create(this, Id, Name, 1);
	ListItem->OnDeleteCharacter.BindUObject(this, &ThisClass::OnDeleteCharacter);
	ListView->AddItem(ListItem);

	// Navigate to the list item we just created and added
	ListView->RequestNavigateToItem(ListItem);
}

void UChooseCharacter_Activatable::OnDeleteCharacter(UObject* ListItem)
{
	if (auto* CharacterListItem = Cast<UCharacterListItem>(ListItem))
	{
		CharacterListItem->OnDeleteCharacter.Unbind();
	}

	ListView->RemoveItem(ListItem);
}

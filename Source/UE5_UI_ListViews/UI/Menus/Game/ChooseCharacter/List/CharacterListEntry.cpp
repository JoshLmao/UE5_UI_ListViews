// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterListEntry.h"

#include "CharacterListItem.h"
#include "CommonTextBlock.h"
#include "UE5_UI_ListViews/UI/Common/Button/TextButton.h"

void UCharacterListEntry::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	DeleteCharacterButton->OnClicked().AddUObject(this, &ThisClass::OnDeleteCharacterClicked);
}

void UCharacterListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto* ExpectedListItem = Cast<UCharacterListItem>(ListItemObject);
	if (!IsValid(ExpectedListItem))
	{
		return;
	}

	CharacterListItem = ExpectedListItem;
	UpdateWidget(CharacterListItem);
}

void UCharacterListEntry::UpdateWidget(const UCharacterListItem* ListItem) const
{
	NameTextBlock->SetText(ListItem->Name);
	LevelTextBlock->SetText(FText::AsNumber(ListItem->Level));
}

void UCharacterListEntry::OnDeleteCharacterClicked()
{
	CharacterListItem->OnDeleteCharacter.ExecuteIfBound(CharacterListItem);
}
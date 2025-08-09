// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterListEntry.h"

#include "CharacterListItem.h"
#include "CommonTextBlock.h"

void UCharacterListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);

	auto* CharacterListItem = Cast<UCharacterListItem>(ListItemObject);
	if (!IsValid(CharacterListItem))
	{
		return;
	}

	UpdateWidget(CharacterListItem);
}

void UCharacterListEntry::UpdateWidget(const UCharacterListItem* ListItem) const
{
	NameTextBlock->SetText(ListItem->Name);
	LevelTextBlock->SetText(FText::AsNumber(ListItem->Level));
}
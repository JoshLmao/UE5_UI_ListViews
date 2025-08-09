// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterListEntry.h"

void UCharacterListEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	Super::NativeOnListItemObjectSet(ListItemObject);
	UpdateWidget(ListItemObject);
}

void UCharacterListEntry::UpdateWidget(const UObject* ListItem)
{
	// todo connect data to bindings
}
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/ListItemBase.h"
#include "CharacterListItem.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UCharacterListItem : public UListItemBase
{
	GENERATED_BODY()

public:
	static UCharacterListItem* Create(UObject* Owner, const FName& InId, const FText& InName, int32 InLevel)
	{
		auto* ListItem = NewObject<UCharacterListItem>();
		ListItem->Id = InId;
		ListItem->Name = InName;
		ListItem->Level = InLevel;
		return ListItem;
	}

	FText Name = FText::FromString("unnamed");
	FName Id;
	int Level = 0;

	DECLARE_DELEGATE_OneParam(FOnDeleteCharacter, UObject* /*ListItem*/);
	FOnDeleteCharacter OnDeleteCharacter;
};

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
	static UCharacterListItem* Create(UObject* Owner, const FName& InId, const FText& InName)
	{
		auto* ListItem = NewObject<UCharacterListItem>(Owner);
		ListItem->Id = InId;
		ListItem->Name = InName;
		return ListItem;
	}

	FText Name;
	FName Id;
};

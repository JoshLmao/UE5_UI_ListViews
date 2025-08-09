// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListEntryBase.h"
#include "CharacterListEntry.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UCharacterListEntry : public UMyListEntryBase
{
	GENERATED_BODY()

protected:
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;

private:
	void UpdateWidget(const UObject* ListItem);

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* NameTextBlock;

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* LevelTextBlock;
};

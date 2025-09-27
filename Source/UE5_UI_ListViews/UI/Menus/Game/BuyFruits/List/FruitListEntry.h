// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListEntryBase.h"
#include "FruitListEntry.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UFruitListEntry : public UMyListEntryBase
{
	GENERATED_BODY()

protected:
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;

private:
	void UpdateWidget(const FName& ID) const;

	FName FruitID;

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* NameTextBlock;
	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* IDTextBlock;
};

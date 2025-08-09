// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/ListEntryDataBase.h"
#include "SettingsListItemBase.generated.h"

/*
 * Base implementation and properties needed across all Settings list entries
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettingsListItemBase : public UListEntryDataBase
{
	GENERATED_BODY()

public:
	FText GetTitle()
	{
		return TitleText;
	}

	void SetTitle(const FText& InTitle)
	{
		TitleText = InTitle;
	}

private:
	FText TitleText;
};

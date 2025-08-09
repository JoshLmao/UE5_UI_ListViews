// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Menus/Settings/ListEntry/SettingsListEntryBase.h"
#include "SettingsListEntry_Title.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API USettingsListEntry_Title : public USettingsListEntryBase
{
	GENERATED_BODY()

public:
	USettingsListEntry_Title()
	{
		SetIsFocusable(false);
	}
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Scenario/Settings/ListEntry/SettingsListEntryBase.h"
#include "SettingsListEntry_Missing.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API USettingsListEntry_Missing : public USettingsListEntryBase
{
	GENERATED_BODY()

protected:
	void NativePreConstruct() override;
};

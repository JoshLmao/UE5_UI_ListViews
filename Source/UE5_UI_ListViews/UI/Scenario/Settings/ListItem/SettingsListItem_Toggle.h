// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsListItemBase.h"
#include "SettingsListItem_Toggle.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettingsListItem_Toggle : public USettingsListItemBase
{
	GENERATED_BODY()

public:
	bool GetToggleStatus() const
	{
		return ToggleStatus;
	}

	void SetToggleStatus(const bool InStatus)
	{
		ToggleStatus = InStatus;
	}

private:
	bool ToggleStatus;
};

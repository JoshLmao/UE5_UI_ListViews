// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsListItemBase.h"
#include "SettingsListItem_Title.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettingsListItem_Title : public USettingsListItemBase
{
	GENERATED_BODY()

public:
	USettingsListItem_Title()
	{
		SetIsSelectable(false);
	}
};

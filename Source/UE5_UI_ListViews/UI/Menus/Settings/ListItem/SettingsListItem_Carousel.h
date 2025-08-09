// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SettingsListItemBase.h"
#include "SettingsListItem_Carousel.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettingsListItem_Carousel : public USettingsListItemBase
{
	GENERATED_BODY()

public:
	TArray<FText> GetOptions()
	{
		return CarouselOptions;
	}

	void SetOptions(const TArray<FText>& InOptions)
	{
		CarouselOptions = InOptions;
	}

private:
	TArray<FText> CarouselOptions;
};

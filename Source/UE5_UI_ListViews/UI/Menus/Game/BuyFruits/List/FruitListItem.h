// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/ListItemBase.h"
#include "FruitListItem.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UFruitListItem : public UListItemBase
{
	GENERATED_BODY()

public:
	FName ID;
};

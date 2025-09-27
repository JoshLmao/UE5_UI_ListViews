// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "BuyFruits_Activatable.generated.h"

/**
 * Method 2:
 *
 * Populating ListItems using only an Index/Key.
 * Using the key to look up data via an external data source (such as a UI State, etc)
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UBuyFruits_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

	UBuyFruits_Activatable();

protected:
	void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UMyListViewBase* ListView;
};

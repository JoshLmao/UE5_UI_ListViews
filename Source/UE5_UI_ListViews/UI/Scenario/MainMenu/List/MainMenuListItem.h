// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UE5_UI_ListViews/UI/Common/ListView/ListEntryDataBase.h"
#include "MainMenuListItem.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UMainMenuListItem : public UListEntryDataBase
{
	GENERATED_BODY()

public:
	static UMainMenuListItem* MakeListItem(UObject* Owner, const FText& InText, UObject* InDelegateObject, FName InFunctionName)
	{
		auto* ListItem = NewObject<UMainMenuListItem>();
		ListItem->Text = InText;
		ListItem->ListItemClickedDelegate.BindUFunction(InDelegateObject, InFunctionName);
		return ListItem;
	}

	UPROPERTY(EditAnywhere)
	FText Text;

	DECLARE_DYNAMIC_DELEGATE_OneParam(FOnListItemClicked, UObject*, ListItem);
	UPROPERTY()
	FOnListItemClicked ListItemClickedDelegate;
};

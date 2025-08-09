// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UE5_UI_ListViews/UI/Common/ListView/ListItemBase.h"
#include "Matchmake_Activatable.generated.h"

UCLASS()
class USimpleListItem : public UListItemBase
{
	GENERATED_BODY()

public:
	static USimpleListItem* Create(UObject* Owner, const FName& RegionId, const FText& InText)
	{
		auto* ListItem = NewObject<USimpleListItem>(Owner);
		ListItem->Id = RegionId;
		ListItem->Text = InText;
		return ListItem;
	}

	FName Id;
	FText Text;
};

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UMatchmake_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UMatchmake_Activatable();

protected:
	void NativeOnInitialized() override;
	void NativePreConstruct() override;
	void NativeConstruct() override;
	bool NativeOnHandleBackAction() override;

	FReply NativeOnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;

private:
	void OnListViewItemSelectionChanged(UObject* ListItem);

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* TitleTextBlock;

	UPROPERTY(meta = (BindWidget))
	class UMyListViewBase* ListView;
};

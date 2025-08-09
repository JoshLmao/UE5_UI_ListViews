// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Matchmake_Activatable.h"
#include "UE5_UI_ListViews/UI/Common/ListView/MyListEntryBase.h"
#include "MatchmakeRegionListEntry.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UMatchmakeRegionListEntry : public UMyListEntryBase
{
	GENERATED_BODY()

public:
	UMatchmakeRegionListEntry();

protected:
	void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	void NativeOnItemSelectionChanged(bool bIsSelected) override;

	void UpdateWidget(const class USimpleListItem* ListItem);

private:
	void UpdateBackgroundColor() const;

	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* RegionTextBlock;

	UPROPERTY(meta = (BindWidget))
	class UCommonLazyImage* CheckedImage;

	UPROPERTY(meta = (BindWidget))
	class UCommonBorder* RootBorder;

	UPROPERTY(EditDefaultsOnly)
	FLinearColor SelectedBackground;

	UPROPERTY(EditDefaultsOnly)
	FLinearColor UnselectedBackground;
};

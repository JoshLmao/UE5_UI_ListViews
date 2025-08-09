#pragma once

#include <CoreMinimal.h>

#include <Components/ListView.h>

#include "MyListViewBase.generated.h"

UCLASS()
class UE5_UI_LISTVIEWS_API UMyListViewBase : public UListView
{
	GENERATED_BODY()

protected:
	UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;

	bool OnIsSelectableOrNavigableInternal(UObject* SelectedItem) override;

private:
	// Populate with ListItems to their correlating ListEntry user widgets
	UPROPERTY(EditAnywhere)
	TMap<TSubclassOf<class UListItemBase>, TSubclassOf<UUserWidget>> ListItemMap;
};

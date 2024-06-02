#pragma once

#include <CoreMinimal.h>

#include <Components/ListView.h>

#include "MyListViewBase.generated.h"

UCLASS()
class UE5_UI_LISTVIEWS_API UMyListViewBase : public UListView
{
	GENERATED_BODY()

protected:
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;

	UFUNCTION(ScriptCallable, BlueprintImplementableEvent, Meta = (BlueprintProtected = "true"))
	TSubclassOf<UUserWidget> AS_GetItemDesiredEntryClass(UObject* Item);

	bool OnIsSelectableOrNavigableInternal(UObject* SelectedItem) override;
};

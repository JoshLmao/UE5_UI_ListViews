#include "MyListViewBase.h"

#include "ListItemBase.h"

UUserWidget& UMyListViewBase::OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable)
{
	// Search the ListItemMap for a user configured ListEntryWidgetClass that matches the incoming Item class
	for (const auto& [ListItemClass, ListEntryWidgetClass] : ListItemMap)
	{
		if (IsValid(ListItemClass) && Item->IsA(ListItemClass) && IsValid(ListEntryWidgetClass))
		{
			return Super::OnGenerateEntryWidgetInternal(Item, ListEntryWidgetClass, OwnerTable);
		}
	}

	// When no correlating ListEntry has been found in ListItemMap,
	// fallback to using the default ListView's DesiredEntryClass
	return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
}

bool UMyListViewBase::OnIsSelectableOrNavigableInternal(UObject* SelectedItem)
{
	// Check the list entry data to determine if this is selectable
	if (auto ListEntryBase = Cast<UListItemBase>(SelectedItem))
	{
		return ListEntryBase->GetIsSelectable();
	}
	return false;
}

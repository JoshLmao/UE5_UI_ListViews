#include "MyListViewBase.h"

#include "ListEntryDataBase.h"

UUserWidget& UMyListViewBase::OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable)
{
	TSubclassOf<UUserWidget> OverrideDesiredEntryClass = AS_GetItemDesiredEntryClass(Item);
	if (IsValid(OverrideDesiredEntryClass.Get())) // If a custom entry class has been set
	{
		UUserWidget& CreatedEntry = GenerateTypedEntry<UUserWidget>(OverrideDesiredEntryClass, OwnerTable);
		return CreatedEntry;
	}
	return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
}

bool UMyListViewBase::OnIsSelectableOrNavigableInternal(UObject* SelectedItem)
{
	if (auto ListEntryBase = Cast<UListEntryDataBase>(SelectedItem))
	{
		return ListEntryBase->GetIsSelectable();
	}
	return false;
}

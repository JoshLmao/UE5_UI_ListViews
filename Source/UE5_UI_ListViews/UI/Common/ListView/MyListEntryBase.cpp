#include "MyListEntryBase.h"

void UMyListEntryBase::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	AS_NativeOnListItemObjectSet(ListItemObject);
}

void UMyListEntryBase::NativeOnEntryReleased()
{
	AS_NativeOnEntryReleased();
}

bool UMyListEntryBase::AS_IsListItemSelected()
{
	return IsListItemSelected();
}

void UMyListEntryBase::NativeOnItemSelectionChanged(bool bIsSelected)
{
	AS_NativeOnItemSelectionChanged(bIsSelected);
}

#include "MyListEntryBase.h"

void UMyListEntryBase::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	AS_NativeOnListItemObjectSet(ListItemObject);
}

void UMyListEntryBase::NativeOnEntryReleased()
{
	AS_NativeOnEntryReleased();
}

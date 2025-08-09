#pragma once

#include <CoreMinimal.h>

#include "ListItemBase.generated.h"

/*
 * Base List Item class, should be used for any list item class that pass data to a list entry
 */
UCLASS(Abstract)
class UListItemBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(ScriptCallable)
	bool GetIsSelectable()
	{
		return bIsSelectable;
	}

	UFUNCTION(ScriptCallable)
	void SetIsSelectable(bool InbIsSelectable)
	{
		bIsSelectable = InbIsSelectable;
	}

	// Able to check if this entry is selectable or not
	bool bIsSelectable = true;
};
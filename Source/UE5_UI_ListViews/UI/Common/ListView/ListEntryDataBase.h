#pragma once

#include <CoreMinimal.h>

#include "ListEntryDataBase.generated.h"

/*
 * Base entry data class, should be used for any list entry data class
 */
UCLASS(Abstract)
class UListEntryDataBase : public UObject
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
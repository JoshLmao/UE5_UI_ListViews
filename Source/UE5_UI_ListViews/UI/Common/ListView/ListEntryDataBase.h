#pragma once

#include <CoreMinimal.h>

#include "ListEntryDataBase.generated.h"

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

	bool bIsSelectable = true;
};
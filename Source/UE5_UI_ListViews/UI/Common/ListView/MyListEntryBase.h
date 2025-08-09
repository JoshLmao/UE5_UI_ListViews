#pragma once

#include <Blueprint/IUserObjectListEntry.h>
#include <CoreMinimal.h>
#include "CommonUserWidget.h"

#include "MyListEntryBase.generated.h"

UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UMyListEntryBase : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
};

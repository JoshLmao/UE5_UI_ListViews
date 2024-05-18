#pragma once

#include <CoreMinimal.h>
#include <Blueprint/IUserObjectListEntry.h>
#include <Blueprint/UserWidget.h>

#include "MyListEntryBase.generated.h"

UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UMyListEntryBase : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	void NativeOnListItemObjectSet(class UObject* ListItemObject) override;

	// For AS, need to expose a blueprintable event to implement, AS can't use interfaces
	UFUNCTION(ScriptCallable, BlueprintImplementableEvent, Meta = (BlueprintProtected = "true"))
	void AS_NativeOnListItemObjectSet(class UObject* ListItemObject);
};

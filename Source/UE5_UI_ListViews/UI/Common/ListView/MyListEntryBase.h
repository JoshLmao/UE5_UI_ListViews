#pragma once

#include <Blueprint/IUserObjectListEntry.h>
#include <CoreMinimal.h>
#include "CommonUserWidget.h"

#include "MyListEntryBase.generated.h"

UCLASS(Abstract)
class UE5_UI_LISTVIEWS_API UMyListEntryBase : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	/* begin IUserObjectListEntry */
	void NativeOnListItemObjectSet(class UObject* ListItemObject) override;
	// AS: Relay BlueprintImplementableEvent
	UFUNCTION(ScriptCallable, BlueprintImplementableEvent, Meta = (BlueprintProtected = "true"))
	void AS_NativeOnListItemObjectSet(class UObject* ListItemObject);
	/* end IUserObjectListEntry */


	/* begin IUserListEntry */
	void NativeOnEntryReleased();
	// AS: Relay BlueprintImplementableEvent
	UFUNCTION(ScriptCallable, BlueprintImplementableEvent, Meta = (BlueprintProtected = "true"))
	void AS_NativeOnEntryReleased();

	void NativeOnItemSelectionChanged(bool bIsSelected) override;
	UFUNCTION(ScriptCallable, BlueprintImplementableEvent, Meta = (BlueprintProtected = "true"))
	void AS_NativeOnItemSelectionChanged(bool bIsSelected);
	/* end IUserListEntry */

	UFUNCTION(ScriptCallable)
	bool AS_IsListItemSelected();
};

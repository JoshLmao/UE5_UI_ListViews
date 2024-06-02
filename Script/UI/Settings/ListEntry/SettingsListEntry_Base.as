/*
	Settings List Entry Base:
	Shared list entry across all custom settings list entries.
	Should copy properties in `UAS_Settings_ListEntryData_Base` as they'll be shared across
*/
UCLASS(Abstract)
class UAS_SettingsListEntry_Base : UMyListEntryBase
{
	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		if (IsDesignTime)
		{
			TitleTextBlock.SetText(FText::FromString("A List Entry Title"));
		}
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
		auto ListEntryTitle = Cast<UAS_Settings_ListEntryData_Base>(ListItemObject);
		if (!IsValid(ListEntryTitle))
		{
			return;
		}

		TitleTextBlock.SetText(ListEntryTitle.GetTitle());
	}

	UFUNCTION(BlueprintOverride)
	FEventReply OnFocusReceived(FGeometry MyGeometry, FFocusEvent InFocusEvent)
	{
		auto UserWidgetToFocus = Settings_GetFocusTarget();
		if (IsValid(UserWidgetToFocus))
		{
			return FEventReply::Handled().SetUserFocus(UserWidgetToFocus);
		}
		return FEventReply::Unhandled();
	}

	UUserWidget Settings_GetFocusTarget()
	{
		return nullptr;
	}

	UPROPERTY(BindWidget)
	private UTextBlock TitleTextBlock;
}
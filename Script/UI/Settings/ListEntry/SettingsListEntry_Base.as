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

	UPROPERTY(BindWidget)
	private UTextBlock TitleTextBlock;
}
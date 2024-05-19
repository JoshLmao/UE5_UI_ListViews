UCLASS(Abstract)
class UAS_SettingsListView : UAS_MyListViewBase
{
	UFUNCTION(BlueprintOverride)
	TSubclassOf<UUserWidget> GetItemDesiredEntryClass(UObject Item)
	{
		auto IsTitle = Cast<UAS_ListEntryData_Title>(Item);
		if (IsValid(IsTitle))
		{
			return TitleListEntry;
		}

		return UnknownListEntry; // Given list item doesn't have a configured ListEntry
	}

	// Default list entry to use when miss-configured data entry
	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> UnknownListEntry;

	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> TitleListEntry;
}
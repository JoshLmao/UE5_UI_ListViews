UCLASS(Abstract)
class UAS_SettingsListView : UAS_MyListViewBase
{
	UFUNCTION(BlueprintOverride)
	TSubclassOf<UUserWidget> GetItemDesiredEntryClass(UObject Item)
	{
		/// Map all data UObject's to their UUserWidget implementation

		auto IsTitle = Cast<UAS_Settings_ListEntryData_Title>(Item);
		if (IsValid(IsTitle))
		{
			return TitleListEntryClass;
		}

		auto IsCarousel = Cast<UAS_Settings_ListEntryData_Carousel>(Item);
		if (IsValid(IsCarousel))
		{
			return CarouselListEntryClass;
		}

		return UnknownListEntryClass; // Given list item doesn't have a configured ListEntry
	}

	// Default list entry to use when miss-configured data entry
	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> UnknownListEntryClass;

	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> TitleListEntryClass;

	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> CarouselListEntryClass;
}
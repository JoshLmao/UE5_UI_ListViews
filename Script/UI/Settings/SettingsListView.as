UCLASS(Abstract)
class UAS_SettingsListView : UAS_MyListViewBase
{
	// Default list entry to use when miss-configured data entry
	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> UnknownListEntryClass;

	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> TitleListEntryClass;

	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> CarouselListEntryClass;

	UPROPERTY(EditDefaultsOnly)
	private TSubclassOf<UUserWidget> ToggleListEntryClass;
}
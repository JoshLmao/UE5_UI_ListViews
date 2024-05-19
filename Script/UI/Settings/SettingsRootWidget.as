UCLASS(Abstract)
class UAS_SettingsRootWidget : UUserWidget
{
	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		// TODO: Move out of here to a registry class.
		// Should say here `TArray<UObject> AllGeneralSettings = GetSettingsGeneral();`
		TArray<UObject> AllGeneralSettings;

		UAS_ListEntryData_Title Title = UAS_ListEntryData_Title();
		Title.SetTitle(FText::FromString("General"));
		AllGeneralSettings.Add(Title);

		SettingsGeneralListView.SetListItems(AllGeneralSettings);
	}

	UPROPERTY(BindWidget)
	private UAS_SettingsListView SettingsGeneralListView;
}
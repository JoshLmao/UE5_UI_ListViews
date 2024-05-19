UCLASS(Abstract)
class UAS_SettingsRootWidget : UUserWidget
{
	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		TArray<UObject> AllSettingsGeneral = Settings::Registry::GetSettings_General();
		SettingsGeneralListView.SetListItems(AllSettingsGeneral);
	}

	UPROPERTY(BindWidget)
	private UAS_SettingsListView SettingsGeneralListView;
}
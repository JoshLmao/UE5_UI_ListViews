UCLASS(Abstract)
class UAS_SettingsRootWidget : UCommonActivatableWidget
{
	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		TArray<UObject> AllSettingsGeneral = Settings::Registry::GetSettings_General();
		SettingsGeneralListView.SetListItems(AllSettingsGeneral);
	}

	UFUNCTION(BlueprintOverride)
	void OnInitialized()
	{
		BackButton.OnClicked.AddUFunction(this, n"OnBackButtonClicked");
	}

	UFUNCTION()
	private void OnBackButtonClicked()
	{
		auto HUDControl = Cast<AMainMenuHUD>(GetOwningPlayer().GetHUD());
		HUDControl.OpenWidget(GameplayTags::UI_MainMenu_Landing);
	}

	UFUNCTION(BlueprintOverride)
	UWidget BP_GetDesiredFocusTarget() const
	{
		return SettingsGeneralListView;
	}

	UPROPERTY(BindWidget)
	private UAS_SettingsListView SettingsGeneralListView;

	UPROPERTY(BindWIdget)
	private UButton BackButton;

	default bIsFocusable = true;
}
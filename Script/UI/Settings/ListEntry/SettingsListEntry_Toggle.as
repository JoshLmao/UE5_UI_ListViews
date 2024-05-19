UCLASS(Abstract)
class UAS_SettingsListEntry_Toggle : UAS_SettingsListEntry_Base
{

	UPROPERTY(BindWidget)
	private UButton ToggleButton;

	UPROPERTY(BindWidget)
	private UTextBlock StatusTextBlock;

	UFUNCTION(BlueprintOverride)
	void OnInitialized()
	{
		ToggleButton.OnClicked.AddUFunction(this, n"OnToggleButtonClicked");
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
		Super::NativeOnListItemObjectSet(ListItemObject);

		auto ToggleData = Cast<UAS_Settings_ListEntryData_Toggle>(ListItemObject);
		if (!IsValid(ToggleData))
		{
			return;
		}

		SetStatus(ToggleData.GetToggleStatus());
	}

	UFUNCTION()
	private void OnToggleButtonClicked()
	{
		SetStatus(!CurrentStatus);
	}

	private void SetStatus(bool InStatus)
	{
		CurrentStatus = InStatus;
		StatusTextBlock.SetText(InStatus ? FText::FromString("Enabled") : FText::FromString("Disabled"));
	}

	private bool CurrentStatus;
}
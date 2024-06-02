/*
	Settings List Entry Carousel:
	Shows a list of options but only allowing one to be selected.
*/
UCLASS(Abstract)
class UAS_SettingsListEntry_Carousel : UAS_SettingsListEntry_Base
{
	UFUNCTION(BlueprintOverride)
	void OnInitialized()
	{
		LeftButton.OnClicked.AddUFunction(this, n"OnLeftButtonClicked");
		RightButton.OnClicked.AddUFunction(this, n"OnRightButtonClicked");
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
		Super::NativeOnListItemObjectSet(ListItemObject);

		auto CarouselData = Cast<UAS_Settings_ListEntryData_Carousel>(ListItemObject);
		if (!IsValid(CarouselData))
		{
			return;
		}

		AllOptions = CarouselData.GetOptions();
		Rotator.PopulateTextLabels(AllOptions);
		Rotator.SetSelectedItem(0);
	}

	UWidget Settings_GetFocusTarget() override
	{
		return Rotator;
	}

	UFUNCTION()
	private void OnLeftButtonClicked()
	{
		Rotator.ShiftTextLeft();
	}

	UFUNCTION()
	private void OnRightButtonClicked()
	{
		Rotator.ShiftTextRight();
	}

	// All available options
	private TArray<FText> AllOptions;

	UPROPERTY(BindWidget)
	private UButton LeftButton;

	UPROPERTY(BindWidget)
	private UButton RightButton;

	UPROPERTY(BindWidget)
	private UCommonRotator Rotator;
}
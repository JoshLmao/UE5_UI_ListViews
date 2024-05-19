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
		ActiveOption = 0;
		UpdateActiveText();
	}

	UFUNCTION()
	private void OnLeftButtonClicked()
	{
		ActiveOption--;
		if (ActiveOption < 0)
		{
			ActiveOption = AllOptions.Num() - 1;
		}
		UpdateActiveText();
	}

	UFUNCTION()
	private void OnRightButtonClicked()
	{
		ActiveOption++;
		if (ActiveOption >= AllOptions.Num())
		{
			ActiveOption = 0;
		}
		UpdateActiveText();
	}

	private void UpdateActiveText()
	{
		ActiveOptionTextBlock.SetText(AllOptions[ActiveOption]);
	}

	// Active index of the option active now
	private int ActiveOption = 0;
	// All available options
	private TArray<FText> AllOptions;

	UPROPERTY(BindWidget)
	private UButton LeftButton;

	UPROPERTY(BindWidget)
	private UButton RightButton;

	UPROPERTY(BindWidget)
	private UTextBlock ActiveOptionTextBlock;
}
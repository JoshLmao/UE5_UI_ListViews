UCLASS(Abstract)
class UAS_MatchmakeRegionListEntry : UAS_MyListEntryBase
{
	// As this entry wont use a button as its base, we need to ensure the whole widget is hit testable and able to be clicked
	default Visibility = ESlateVisibility::Visible;

	private UAS_SimpleProp Prop;

	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		// if (!IsDesignTime)
		// {
		// 	UpdateBackgroundColor();
		// }
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
		auto CastedProp = Cast<UAS_SimpleProp>(ListItemObject);
		if (IsValid(CastedProp))
		{
			Prop = CastedProp;
			UpdateWidget();
		}
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnItemSelectionChanged(bool bIsSelected)
	{
		Print(GetName() + " SelectionChanged " + bIsSelected);
		UpdateBackgroundColor();
	}

	private void UpdateWidget()
	{
		RegionTextBlock.SetText(Prop.Value);
		UpdateBackgroundColor();
	}

	private void UpdateBackgroundColor()
	{
		RootBorder.SetBrushColor(IsListItemSelected() ? SelectedBackground : UnselectedBackground);
	}

	UGameInstanceSubsystem GetGameInstanceSS() property
	{
		return nullptr;
	}

	UWorldSubsystem GetWorldSS() property
	{
		return nullptr;
	}

	UPROPERTY(BindWidget)
	private UCommonTextBlock RegionTextBlock;

	UPROPERTY(BindWidget)
	private UCommonLazyImage CheckedImage;

	UPROPERTY(BindWidget)
	private UCommonBorder RootBorder;

	UPROPERTY(EditDefaultsOnly)
	private FLinearColor SelectedBackground;
	UPROPERTY(EditDefaultsOnly)
	private FLinearColor UnselectedBackground;
}
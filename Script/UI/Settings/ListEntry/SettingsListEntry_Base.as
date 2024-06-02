/*
	Settings List Entry Base:
	Shared list entry across all custom settings list entries.
	Should copy properties in `UAS_Settings_ListEntryData_Base` as they'll be shared across
*/
UCLASS(Abstract)
class UAS_SettingsListEntry_Base : UMyListEntryBase
{
	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		if (IsDesignTime)
		{
			TitleTextBlock.SetText(FText::FromString("A List Entry Title"));
		}
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
		auto ListEntryTitle = Cast<UAS_Settings_ListEntryData_Base>(ListItemObject);
		if (!IsValid(ListEntryTitle))
		{
			return;
		}

		TitleTextBlock.SetText(ListEntryTitle.GetTitle());
	}

	UFUNCTION(BlueprintOverride)
	FEventReply OnFocusReceived(FGeometry MyGeometry, FFocusEvent InFocusEvent)
	{
		// Get child's UWidget to direct focus onto
		auto UserWidgetToFocus = Settings_GetFocusTarget();
		if (IsValid(UserWidgetToFocus))
		{
			return FEventReply::Handled().SetUserFocus(UserWidgetToFocus);
		}
		return FEventReply::Unhandled();
	}

	UWidget Settings_GetFocusTarget()
	{
		// Acting as a virtual, each ListEntry should override and specify what to focus
		return nullptr;
	}

	UFUNCTION(BlueprintOverride)
	void OnMouseEnter(FGeometry MyGeometry, FPointerEvent MouseEvent)
	{
		if (IsValid(OnHover))
		{
			PlayAnimation(OnHover);
		}
	}

	UFUNCTION(BlueprintOverride)
	void OnMouseLeave(FPointerEvent MouseEvent)
	{
		if (IsValid(OnHover))
		{
			PlayAnimationReverse(OnHover);
		}
	}

	UFUNCTION(BlueprintOverride)
	void NativeOnEntryReleased()
	{
		StopAllAnimations();
	}

	UPROPERTY(BindWidget)
	private UTextBlock TitleTextBlock;

	UPROPERTY(Transient, meta = (BindWidgetAnimOptional))
	private UWidgetAnimation OnHover;
}
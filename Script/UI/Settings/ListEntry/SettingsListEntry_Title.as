UCLASS(Abstract)
class UAS_SettingsListEnty_Title : UAS_MyListEntryBase
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
		auto LisEntryTitle = Cast<UAS_ListEntryData_Title>(ListItemObject);
		if (!IsValid(LisEntryTitle))
		{
			return;
		}

		TitleTextBlock.SetText(LisEntryTitle.GetTitle());
	}

	UPROPERTY(BindWidget)
	private UTextBlock TitleTextBlock;
}
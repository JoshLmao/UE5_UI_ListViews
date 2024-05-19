UCLASS(Abstract)
class UAS_SettingsListEnty_Missing : UAS_MyListEntryBase
{
	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		MissingTextBlock.SetText(FText::FromString("Missing list entry for this data"));
	}

	UPROPERTY(BindWidget)
	private UTextBlock MissingTextBlock;
}
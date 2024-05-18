UCLASS(Abstract)
class UAS_MainMenuButtonsListEntry : UAS_MyListEntryBase
{

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
		auto ExpectedProp = Cast<UAS_MainMenuListProp>(ListItemObject);
		if (!IsValid(ExpectedProp))
		{
			return;
		}

		TextBlock.SetText(ExpectedProp.ButtonText);
	}

	UPROPERTY(BindWidget)
	private UButton Button;

	UPROPERTY(BindWidget)
	private UTextBlock TextBlock;
}
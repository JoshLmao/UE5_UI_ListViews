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

		// TODO: Use UUserObjectListEntryLibrary::GetListItemObject to get prop instead of caching it?
		Prop = ExpectedProp;

		TextBlock.SetText(ExpectedProp.ButtonText);
	}

	UFUNCTION(BlueprintOverride)
	void OnInitialized()
	{
		Button.OnClicked.AddUFunction(this, n"OnEntryButtonClicked");
	}

	UFUNCTION()
	private void OnEntryButtonClicked()
	{
		Print(GetName() + " clicked");
		Prop.EntryClickedDelegate.Broadcast(Prop);
	}

	UPROPERTY(BindWidget)
	private UButton Button;

	UPROPERTY(BindWidget)
	private UTextBlock TextBlock;

	private UAS_MainMenuListProp Prop;
}
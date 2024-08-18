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

		Button.SetText(ExpectedProp.ButtonText);
	}

	UFUNCTION(BlueprintOverride)
	void OnInitialized()
	{
		Button.OnButtonBaseClicked.AddUFunction(this, n"OnEntryButtonClicked");
	}

	UFUNCTION()
	private void OnEntryButtonClicked(UCommonButtonBase InButton)
	{
		Print(GetName() + " clicked");
		Prop.EntryClickedDelegate.Broadcast(Prop);
	}

	UPROPERTY(BindWidget)
	private UAS_MyProjectButton Button;

	private UAS_MainMenuListProp Prop;
}
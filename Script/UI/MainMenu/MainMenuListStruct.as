event void OnEntryClicked(UObject Entry);

class UAS_MainMenuListProp
{
	UPROPERTY()
	FText ButtonText;

	UPROPERTY()
	OnEntryClicked EntryClickedDelegate;
}

namespace MainMenu
{
	UAS_MainMenuListProp GenerateProp(FText InButtonText, UObject InInstance, FName InFunctionName)
	{
		UAS_MainMenuListProp Prop = UAS_MainMenuListProp();
		Prop.ButtonText = InButtonText;
		Prop.EntryClickedDelegate.AddUFunction(InInstance, InFunctionName);
		return Prop;
	}
}

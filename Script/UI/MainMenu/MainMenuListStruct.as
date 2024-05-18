
class UAS_MainMenuListProp
{
	UPROPERTY()
	FText ButtonText;
}

namespace MainMenu
{
	UAS_MainMenuListProp GenerateProp(UObject OuterObject, FText InButtonText)
	{
		UAS_MainMenuListProp Prop = UAS_MainMenuListProp();
		Prop.ButtonText = InButtonText;
		return Prop;
	}
}

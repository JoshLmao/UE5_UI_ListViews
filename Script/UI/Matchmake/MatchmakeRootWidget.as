class UAS_SimpleProp : UAS_ListEntryDataBase
{
	FText Value;

}

namespace UAS_SimpleProp
{
	UAS_SimpleProp Make(FText Text)
	{
		UAS_SimpleProp Prop = UAS_SimpleProp();
		Prop.Value = Text;
		return Prop;
	}
}

UCLASS(Abstract)
class UAS_MatchmakeRootWidget : UCommonActivatableWidget
{
	default bIsBackHandler = true;
	default bIsBackActionDisplayedInActionBar = true;
	default bIsFocusable = true; // todo

	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		TitleTextBlock.SetText(FText::FromString("Select Matchmake Regions"));

		ListView.SetSelectionMode(ESelectionMode::SingleToggle);

		// Data initialization
		TArray<UObject> AllOptions;
		AllOptions.Add(UAS_SimpleProp::Make(FText::FromString("Europe")));
		AllOptions.Add(UAS_SimpleProp::Make(FText::FromString("Africa")));
		AllOptions.Add(UAS_SimpleProp::Make(FText::FromString("North America")));
		AllOptions.Add(UAS_SimpleProp::Make(FText::FromString("South America")));
		AllOptions.Add(UAS_SimpleProp::Make(FText::FromString("Asia")));
		ListView.SetListItems(AllOptions);
	}

	UFUNCTION(BlueprintOverride)
	void OnInitialized()
	{
	}

	UFUNCTION()
	private void OnEntryClicked(UObject Item)
	{
		Print("ENTRY CLICKED - " + Item);
	}

	UFUNCTION(BlueprintOverride)
	FEventReply OnFocusReceived(FGeometry MyGeometry, FFocusEvent InFocusEvent)
	{
		return FEventReply::Handled().SetUserFocus(ListView);
	}

	UFUNCTION(BlueprintOverride)
	bool OnHandleBackAction()
	{
		Util::GetMainMenuHUD(GetOwningPlayer()).OpenWidget(GameplayTags::UI_MainMenu_Landing);
		return true; // handled
	}

	UPROPERTY(BindWidget)
	private UCommonTextBlock TitleTextBlock;

	UPROPERTY(BindWidget)
	private UMyListViewBase ListView;
}
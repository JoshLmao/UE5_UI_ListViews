UCLASS()
class UAS_MainMenuRootWidget : UUserWidget
{
	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		// Generate and set list view data
		TArray<UObject> AllData;
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Play"), this, n"OnPlayClicked"));
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Matchmake"), this, n"OnMatchmakeClicked"));
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Quit to Desktop"), this, n"OnQuitClicked"));

		ButtonsListView.SetListItems(AllData);
	}

	UFUNCTION()
	void OnPlayClicked(UObject Obj)
	{
		Print("OnPlayClicked");
	}

	UFUNCTION()
	void OnMatchmakeClicked(UObject Obj)
	{
		Print("OnMatchmakeClicked");
	}

	UFUNCTION()
	void OnQuitClicked(UObject Obj)
	{
		Print("OnQuitClicked");
	}

	UPROPERTY(BindWidget)
	private UAS_MainMenuButtonsListView ButtonsListView;
}
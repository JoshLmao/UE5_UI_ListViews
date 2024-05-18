UCLASS()
class UAS_MainMenuRootWidget : UUserWidget
{
	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		// Generate and set list view data
		TArray<UObject> AllData;
		AllData.Add(MainMenu::GenerateProp(this, FText::FromString("Play")));
		AllData.Add(MainMenu::GenerateProp(this, FText::FromString("Matchmake")));
		AllData.Add(MainMenu::GenerateProp(this, FText::FromString("Quit to Desktop")));

		ButtonsListView.SetListItems(AllData);
	}

	UPROPERTY(BindWidget)
	private UAS_MainMenuButtonsListView ButtonsListView;
}
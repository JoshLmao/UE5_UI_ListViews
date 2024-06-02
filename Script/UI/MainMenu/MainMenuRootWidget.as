UCLASS(Abstract)
class UAS_MainMenuRootWidget : UCommonActivatableWidget
{
	UFUNCTION(BlueprintOverride)
	void Construct()
	{
		// Generate and set list view data
		TArray<UObject> AllData;
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Play"), this, n"OnPlayClicked"));
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Matchmake"), this, n"OnMatchmakeClicked"));
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Settings"), this, n"OnSettingsClicked"));
		AllData.Add(MainMenu::GenerateProp(FText::FromString("Quit to Desktop"), this, n"OnQuitClicked"));

		ButtonsListView.SetListItems(AllData);
	}

	UFUNCTION(BlueprintOverride)
	UWidget BP_GetDesiredFocusTarget() const
	{
		return ButtonsListView;
	}

	UFUNCTION()
	void OnPlayClicked(UObject Item)
	{
		Print("OnPlayClicked");
	}

	UFUNCTION()
	void OnMatchmakeClicked(UObject Item)
	{
		Print("OnMatchmakeClicked");
	}

	UFUNCTION()
	void OnSettingsClicked(UObject Item)
	{
		auto HUDControl = Cast<AMainMenuHUD>(GetOwningPlayer().GetHUD());
		HUDControl.OpenWidget(FGameplayTag::RequestGameplayTag(n"UI.MainMenu.Settings"));
	}

	UFUNCTION()
	void OnQuitClicked(UObject Item)
	{
		Print("OnQuitClicked");
	}

	UPROPERTY(BindWidget)
	private UAS_MainMenuButtonsListView ButtonsListView;

	default bIsFocusable = true;
}
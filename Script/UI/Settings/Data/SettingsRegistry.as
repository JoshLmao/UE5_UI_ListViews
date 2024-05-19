namespace Settings
{
	namespace Registry
	{
		TArray<UObject> GetSettings_General()
		{
			TArray<UObject> AllGeneralSettings;

			/// Section Title
			{
				UAS_Settings_ListEntryData_Title Title = UAS_Settings_ListEntryData_Title();
				Title.SetTitle(FText::FromString("General"));
				AllGeneralSettings.Add(Title);
			}

			// Coffee Preferences
			{
				UAS_Settings_ListEntryData_Carousel CoffeePreferenceCarousel = UAS_Settings_ListEntryData_Carousel();
				CoffeePreferenceCarousel.SetTitle(FText::FromString("Coffee Prefs."));
				{
					// Build options
					TArray<FText> AllPrefs;
					AllPrefs.Add(FText::FromString("Black"));
					AllPrefs.Add(FText::FromString("Flat White"));
					AllPrefs.Add(FText::FromString("Cappuccino"));
					AllPrefs.Add(FText::FromString("Espresso"));
					AllPrefs.Add(FText::FromString("Latte"));
					AllPrefs.Add(FText::FromString("Cold Brew"));
					AllPrefs.Add(FText::FromString("Frappe"));
					CoffeePreferenceCarousel.SetOptions(AllPrefs);
				}
				AllGeneralSettings.Add(CoffeePreferenceCarousel);
			}

			return AllGeneralSettings;
		}
	}
}
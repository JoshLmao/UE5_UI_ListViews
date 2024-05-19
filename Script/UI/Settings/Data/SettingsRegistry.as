namespace Settings
{
	namespace Registry
	{
		TArray<UObject> GetSettings_General()
		{
			// Array of all root elements/items that will get inserted into the list view
			TArray<UObject> AllGeneralSettings;

			/// General Section Title
			{
				UAS_Settings_ListEntryData_Title Title = UAS_Settings_ListEntryData_Title();
				Title.SetTitle(FText::FromString("General Section"));
				AllGeneralSettings.Add(Title);
			}

			// Coffee Preferences
			{
				UAS_Settings_ListEntryData_Carousel CoffeePreferenceCarousel = UAS_Settings_ListEntryData_Carousel();
				CoffeePreferenceCarousel.SetTitle(FText::FromString("Coffee Preferences"));
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

			/// Video section title
			{
				UAS_Settings_ListEntryData_Title Title = UAS_Settings_ListEntryData_Title();
				Title.SetTitle(FText::FromString("Video Section"));
				AllGeneralSettings.Add(Title);
			}

			// Window mode
			{
				UAS_Settings_ListEntryData_Carousel WindowModeCarousel = UAS_Settings_ListEntryData_Carousel();
				WindowModeCarousel.SetTitle(FText::FromString("Window Mode"));
				{
					TArray<FText> AllWindowOptions;
					AllWindowOptions.Add(FText::FromString("Fullscreen"));
					AllWindowOptions.Add(FText::FromString("Windowed"));
					AllWindowOptions.Add(FText::FromString("Borderless Windowed"));
					WindowModeCarousel.SetOptions(AllWindowOptions);
				}
				AllGeneralSettings.Add(WindowModeCarousel);
			}

			// Resolutions
			{
				UAS_Settings_ListEntryData_Carousel ResolutionsCarousel = UAS_Settings_ListEntryData_Carousel();
				ResolutionsCarousel.SetTitle(FText::FromString("Window Mode"));
				{
					// TODO: Source these from engine and show actual resolutions
					TArray<FText> AllResolutions;
					AllResolutions.Add(FText::FromString("2560 x 1440"));
					AllResolutions.Add(FText::FromString("1920 x 1080"));
					AllResolutions.Add(FText::FromString("1680 x 1050"));
					AllResolutions.Add(FText::FromString("1440 x 900"));
					AllResolutions.Add(FText::FromString("1280 x 720"));
					AllResolutions.Add(FText::FromString("800 x 600"));
					ResolutionsCarousel.SetOptions(AllResolutions);
				}
				AllGeneralSettings.Add(ResolutionsCarousel);
			}

			// HDR
			{
				UAS_Settings_ListEntryData_Toggle HDRToggle = UAS_Settings_ListEntryData_Toggle();
				HDRToggle.SetTitle(FText::FromString("HDR Enabled"));
				HDRToggle.SetToggleStatus(false); // default value
				AllGeneralSettings.Add(HDRToggle);
			}

			return AllGeneralSettings;
		}
	}
}
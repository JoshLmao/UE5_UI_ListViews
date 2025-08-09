// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsRegistry.h"

#include "UE5_UI_ListViews/UI/Scenario/Settings/ListItem/SettingsListItem_Carousel.h"
#include "UE5_UI_ListViews/UI/Scenario/Settings/ListItem/SettingsListItem_Title.h"
#include "UE5_UI_ListViews/UI/Scenario/Settings/ListItem/SettingsListItem_Toggle.h"

TArray<UObject*> USettingsRegistry::BuildSettings()
{
	TArray<UObject*> AllGeneralSettings;

	/// General Section Title
	{
		USettingsListItem_Title* Title = NewObject<USettingsListItem_Title>();
		Title->SetTitle(FText::FromString("General Section"));
		AllGeneralSettings.Add(Title);
	}

	// Coffee Preferences
	{
		USettingsListItem_Carousel* CoffeePreferenceCarousel = NewObject<USettingsListItem_Carousel>();
		CoffeePreferenceCarousel->SetTitle(FText::FromString("Coffee Preferences"));
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
			CoffeePreferenceCarousel->SetOptions(AllPrefs);
		}
		AllGeneralSettings.Add(CoffeePreferenceCarousel);
	}

	/// Video section title
	{
		USettingsListItem_Title* Title = NewObject<USettingsListItem_Title>();
		Title->SetTitle(FText::FromString("Video Section"));
		AllGeneralSettings.Add(Title);
	}

	// Window mode
	{
		USettingsListItem_Carousel* WindowModeCarousel = NewObject<USettingsListItem_Carousel>();
		WindowModeCarousel->SetTitle(FText::FromString("Window Mode"));
		{
			TArray<FText> AllWindowOptions;
			AllWindowOptions.Add(FText::FromString("Fullscreen"));
			AllWindowOptions.Add(FText::FromString("Windowed"));
			AllWindowOptions.Add(FText::FromString("Borderless Windowed"));
			WindowModeCarousel->SetOptions(AllWindowOptions);
		}
		AllGeneralSettings.Add(WindowModeCarousel);
	}

	// Resolutions
	{
		USettingsListItem_Carousel* ResolutionsCarousel = NewObject<USettingsListItem_Carousel>();
		ResolutionsCarousel->SetTitle(FText::FromString("Window Mode"));
		{
			// TODO: Source these from engine and show actual resolutions
			TArray<FText> AllResolutions;
			AllResolutions.Add(FText::FromString("2560 x 1440"));
			AllResolutions.Add(FText::FromString("1920 x 1080"));
			AllResolutions.Add(FText::FromString("1680 x 1050"));
			AllResolutions.Add(FText::FromString("1440 x 900"));
			AllResolutions.Add(FText::FromString("1280 x 720"));
			AllResolutions.Add(FText::FromString("800 x 600"));
			ResolutionsCarousel->SetOptions(AllResolutions);
		}
		AllGeneralSettings.Add(ResolutionsCarousel);
	}

	// HDR
	{
		USettingsListItem_Toggle* HDRToggle = NewObject<USettingsListItem_Toggle>();
		HDRToggle->SetTitle(FText::FromString("HDR Enabled"));
		HDRToggle->SetToggleStatus(false); // default value
		AllGeneralSettings.Add(HDRToggle);
	}

	return AllGeneralSettings;
}
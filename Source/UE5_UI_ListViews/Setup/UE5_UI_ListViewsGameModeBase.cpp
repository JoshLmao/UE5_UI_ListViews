// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE5_UI_ListViewsGameModeBase.h"

#include "MainMenuHUD.h"
#include "UE5_UI_ListViewsPlayerController.h"

AUE5_UI_ListViewsGameModeBase::AUE5_UI_ListViewsGameModeBase()
{
	PlayerControllerClass = AUE5_UI_ListViewsPlayerController::StaticClass();
	HUDClass = AMainMenuHUD::StaticClass();
}
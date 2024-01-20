// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE5_UI_ListViewsGameModeBase.h"

#include "Setup/UE5_UI_ListViewsPlayerController.h"

AUE5_UI_ListViewsGameModeBase::AUE5_UI_ListViewsGameModeBase()
{
	//HUDClass = AMainHUD::StaticClass();
	PlayerControllerClass = AUE5_UI_ListViewsPlayerController::StaticClass();
}
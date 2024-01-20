// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5_UI_ListViewsPlayerController.h"
#include "Blueprint/UserWidget.h"

void AUE5_UI_ListViewsPlayerController::BeginPlay()
{
	if (MainMenuRootWidget && !MainMenuUWInstance)
	{
		MainMenuUWInstance = CreateWidget<UUserWidget>(this, MainMenuRootWidget);
		if (!MainMenuUWInstance)
		{
			return;
		}

		MainMenuUWInstance->AddToViewport();
	}
}
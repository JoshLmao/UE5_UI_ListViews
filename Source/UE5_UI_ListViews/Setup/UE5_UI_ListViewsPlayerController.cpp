// Fill out your copyright notice in the Description page of Project Settings.


#include "UE5_UI_ListViewsPlayerController.h"

#include <Blueprint/UserWidget.h>

#include <UE5_UI_ListViews/Interface/AnimatedVisibilityInterface.h>

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

		if (MainMenuUWInstance->Implements<UAnimatedVisibilityInterface>())
		{
			auto* AnimatedVisibilityWidget = Cast<IAnimatedVisibilityInterface>(MainMenuUWInstance);
			AnimatedVisibilityWidget->AnimatedVisibility_DoAppear();
		}

		GetWorld()->GetTimerManager().SetTimer(ShowTimeTimerHandle, this, &AUE5_UI_ListViewsPlayerController::OnShowTimeFinished, 5.0f, false);
	}
}

void AUE5_UI_ListViewsPlayerController::OnShowTimeFinished()
{
	if (MainMenuUWInstance->Implements<UAnimatedVisibilityInterface>())
	{
		auto* AnimatedVisibilityWidget = Cast<IAnimatedVisibilityInterface>(MainMenuUWInstance);
		AnimatedVisibilityWidget->AnimatedVisibility_DoDisappear();
	}
}

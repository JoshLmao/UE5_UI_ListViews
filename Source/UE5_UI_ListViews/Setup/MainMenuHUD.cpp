#include "MainMenuHUD.h"

#include <Blueprint/UserWidget.h>

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MainMenuRootWidget && !MainMenuUWInstance)
	{
		MainMenuUWInstance = CreateWidget<UUserWidget>(GetOwningPlayerController(), MainMenuRootWidget);
		if (!MainMenuUWInstance)
		{
			return;
		}

		MainMenuUWInstance->AddToViewport();
	}
}

#include "MainMenuHUD.h"

#include <Blueprint/UserWidget.h>

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
	GetOwningPlayerController()->SetInputMode(InputModeData);

	// Open our landing menu at start
	OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));
}

void AMainMenuHUD::OpenWidget(FGameplayTag WidgetTag)
{
	checkf(UIConfig.Contains(WidgetTag), TEXT("Doesnt have tag!"));

	if (IsValid(ActiveWidget))
	{
		ActiveWidget->RemoveFromViewport();
	}

	ActiveWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), UIConfig[WidgetTag]);
	ActiveWidget->AddToViewport();
	ActiveWidget->SetUserFocus(GetOwningPlayerController());
}

#include "MainMenuHUD.h"

#include <Blueprint/UserWidget.h>

#include "CommonActivatableWidget.h"
#include "PrimaryGameLayout.h"

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

	auto OwningLocalPlayer = GetOwningPlayerController()->GetLocalPlayer();
	if (UPrimaryGameLayout* RootLayout = UPrimaryGameLayout::GetPrimaryGameLayout(OwningLocalPlayer))
	{
		if (IsValid(ActiveActivatable))
		{
			RootLayout->FindAndRemoveWidgetFromLayer(ActiveActivatable);
		}

		auto Layer = FGameplayTag::RequestGameplayTag(TEXT("UI.Layer.Menu"));
		ActiveActivatable = RootLayout->PushWidgetToLayerStack(Layer, UIConfig[WidgetTag]);
		ActiveActivatable->SetUserFocus(GetOwningPlayerController());
	}
}

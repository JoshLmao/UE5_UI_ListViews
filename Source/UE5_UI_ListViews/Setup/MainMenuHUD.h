#pragma once

#include <CoreMinimal.h>
#include <GameFramework/HUD.h>

#include "MainMenuHUD.generated.h"

UCLASS()
class UE5_UI_LISTVIEWS_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UUserWidget> MainMenuRootWidget;

	class UUserWidget* MainMenuUWInstance;
};

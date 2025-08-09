#pragma once

#include <CoreMinimal.h>
#include <GameFramework/HUD.h>
#include <GameplayTagContainer.h>

#include "MainMenuHUD.generated.h"

UCLASS()
class UE5_UI_LISTVIEWS_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void OpenWidget(FGameplayTag WidgetTag);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayTag, TSubclassOf<class UCommonActivatableWidget>> UIConfig;

private:
	UPROPERTY()
	class UCommonActivatableWidget* ActiveActivatable;
};

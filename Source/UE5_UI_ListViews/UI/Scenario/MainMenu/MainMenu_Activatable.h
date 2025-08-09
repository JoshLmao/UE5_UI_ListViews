// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "MainMenu_Activatable.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UMainMenu_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UMainMenu_Activatable();

protected:
	void NativeConstruct() override;

	UWidget* NativeGetDesiredFocusTarget() const override;

private:
	UFUNCTION()
	void OnPlayClicked(const UObject* Item);
	UFUNCTION()
	void OnMatchmakeClicked(const UObject* Item);
	UFUNCTION()
	void OnSettingsClicked(const UObject* Item);
	UFUNCTION()
	void OnQuitToDesktop(const UObject* Item);

	UPROPERTY(meta = (BindWidget))
	class UMyListViewBase* ListView;
};

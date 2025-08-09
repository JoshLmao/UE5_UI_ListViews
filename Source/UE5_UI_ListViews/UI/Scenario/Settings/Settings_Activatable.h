// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Settings_Activatable.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettings_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	USettings_Activatable();

protected:
	void NativeOnInitialized() override;
	void NativeConstruct() override;

	UWidget* NativeGetDesiredFocusTarget() const override;

private:
	void OnButtonBackClicked() const;

	UPROPERTY(meta = (BindWidget))
	class UMyListViewBase* ListView;

	UPROPERTY(meta = (BindWidget))
	class UTextButton* BackButton;
};

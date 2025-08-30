// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameFlowControlUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UGameFlowControlUserWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	void NativeOnInitialized() override;

	UFUNCTION()
	void OnPrevGameClicked() const;
	UFUNCTION()
	void OnNextGameClicked() const;
	UFUNCTION()
	void OnEndGameClicked() const;

private:
	UPROPERTY(meta = (BindWidget))
	class UTextButton* PrevGameButton;
	UPROPERTY(meta = (BindWidget))
	class UTextButton* NextGameButton;
	UPROPERTY(meta = (BindWidget))
	class UTextButton* EndGamesButton;
};

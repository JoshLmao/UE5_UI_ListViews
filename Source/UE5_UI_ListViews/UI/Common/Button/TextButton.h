// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "TextButton.generated.h"

/**
 * Simple text inside of a button
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UTextButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	void SetText(const FText& InText);

protected:
	void NativePreConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UCommonTextBlock* TextBlock;

	UPROPERTY(EditAnywhere)
	FText Text = FText::FromString("Sample Text");
};

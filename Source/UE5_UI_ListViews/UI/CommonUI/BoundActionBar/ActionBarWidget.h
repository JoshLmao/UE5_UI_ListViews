// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ActionBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UActionBarWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UMyBoundActionBar* BoundActionBar;
};

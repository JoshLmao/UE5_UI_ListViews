// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Input/CommonBoundActionButton.h"

#include "MyBoundActionButton.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UMyBoundActionButton : public UCommonBoundActionButton
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
};

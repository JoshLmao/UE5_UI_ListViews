// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SettingsRegistry.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USettingsRegistry : public UObject
{
	GENERATED_BODY()

public:
	static TArray<UObject*> BuildSettings();
};

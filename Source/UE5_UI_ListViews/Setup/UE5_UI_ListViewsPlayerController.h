// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonPlayerController.h"
#include "UE5_UI_ListViewsPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API AUE5_UI_ListViewsPlayerController : public ACommonPlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;
};

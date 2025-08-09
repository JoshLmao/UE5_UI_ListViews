// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonGameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_UI_LISTVIEWS_API UMyGameInstance : public UCommonGameInstance
{
	GENERATED_BODY()

public:
	void SetMatchmakeRegion(const FName& InRegion)
	{
		SelectedRegion = InRegion;
		UE_LOG(LogTemp, Log, TEXT("GI: Data: Updating Matchmaking Region to %s"), *SelectedRegion.ToString());
	}

	FName GetMatchmakeRegion() const
	{
		return SelectedRegion;
	}

private:
	FName SelectedRegion = TEXT("euro");
};

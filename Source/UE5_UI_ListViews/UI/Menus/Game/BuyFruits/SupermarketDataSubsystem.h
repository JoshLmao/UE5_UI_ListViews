// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SupermarketDataSubsystem.generated.h"

struct FFruit
{
	FName ID;
	FText Name;
};

/**
 * A data subsystem, intended to provide data and store it, to mock being like a UI State.
 *
 * I didn't want to build a whole system to show this off, so any calls to this subsystem are
 * where you would come in and replace it with your own :P
 */
UCLASS()
class UE5_UI_LISTVIEWS_API USupermarketDataSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	static USupermarketDataSubsystem* Get(const UWorld* InWorld)
	{
		return InWorld->GetSubsystem<USupermarketDataSubsystem>();
	}

	void Initialize(FSubsystemCollectionBase& Collection) override;

	TArray<FName> GetAllFruitIDs();

	bool GetFruitFromID(const FName& ID, FFruit& OutFruit);

private:
	TArray<FFruit> Fruits;
};

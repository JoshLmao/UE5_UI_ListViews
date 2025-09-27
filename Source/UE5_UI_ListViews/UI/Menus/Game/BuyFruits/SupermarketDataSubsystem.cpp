// Fill out your copyright notice in the Description page of Project Settings.

#include "SupermarketDataSubsystem.h"

void USupermarketDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	Fruits = {
		{ TEXT("0"), FText::FromString("Apple") },		{ TEXT("1"), FText::FromString("Orange") },	   { TEXT("2"), FText::FromString("Pear") },
		{ TEXT("3"), FText::FromString("Watermelon") }, { TEXT("4"), FText::FromString("Grapes") },	   { TEXT("5"), FText::FromString("Strawberry") },
		{ TEXT("6"), FText::FromString("Mango") },		{ TEXT("7"), FText::FromString("Pineapple") }, { TEXT("8"), FText::FromString("Blueberry") },
		{ TEXT("9"), FText::FromString("Cherry") },
	};
}

TArray<FName> USupermarketDataSubsystem::GetAllFruitIDs()
{
	TArray<FName> FruitIDs;
	for (const auto& Fruit : Fruits)
	{
		FruitIDs.Add(Fruit.ID);
	}
	return FruitIDs;
}

bool USupermarketDataSubsystem::GetFruitFromID(const FName& ID, FFruit& OutFruit)
{
	for (const auto& Fruit : Fruits)
	{
		if (Fruit.ID == ID)
		{
			OutFruit = Fruit;
			return true;
		}
	}
	return false;
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TextButton.h"

#include "CommonTextBlock.h"

void UTextButton::SetText(const FText& InText) const
{
	TextBlock->SetText(InText);
}

void UTextButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	TextBlock->SetAutoWrapText(true);
}
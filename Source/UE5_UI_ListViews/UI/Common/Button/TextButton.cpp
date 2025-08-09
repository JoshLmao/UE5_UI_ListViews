// Fill out your copyright notice in the Description page of Project Settings.

#include "TextButton.h"

#include "CommonTextBlock.h"

void UTextButton::SetText(const FText& InText)
{
	Text = InText;
	TextBlock->SetText(Text);
}

void UTextButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	TextBlock->SetText(Text);
	TextBlock->SetAutoWrapText(true);
}
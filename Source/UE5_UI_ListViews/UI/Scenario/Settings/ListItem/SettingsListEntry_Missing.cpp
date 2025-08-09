// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsListEntry_Missing.h"

#include "CommonTextBlock.h"

void USettingsListEntry_Missing::NativePreConstruct()
{
	Super::NativePreConstruct();

	TitleTextBlock->SetText(FText::FromString("Missing list entry for this data!"));
}
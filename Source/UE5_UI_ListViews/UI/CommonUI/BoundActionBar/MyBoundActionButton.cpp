// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBoundActionButton.h"

#include "CommonTextBlock.h"

void UMyBoundActionButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	Text_ActionName->SetAutoWrapText(true);
}
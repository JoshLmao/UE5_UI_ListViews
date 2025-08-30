// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFlowControlUserWidget.h"

#include "CommonButtonBase.h"
#include "GameFlowSubsystem.h"
#include "UE5_UI_ListViews/UI/Common/Button/TextButton.h"

void UGameFlowControlUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	PrevGameButton->OnClicked().AddUObject(this, &ThisClass::OnPrevGameClicked);
	NextGameButton->OnClicked().AddUObject(this, &ThisClass::OnNextGameClicked);
	EndGamesButton->OnClicked().AddUObject(this, &ThisClass::OnEndGameClicked);
}

void UGameFlowControlUserWidget::OnPrevGameClicked() const
{
	GetWorld()->GetSubsystem<UGameFlowSubsystem>()->PreviousGame();
}

void UGameFlowControlUserWidget::OnNextGameClicked() const
{
	GetWorld()->GetSubsystem<UGameFlowSubsystem>()->NextGame();
}

void UGameFlowControlUserWidget::OnEndGameClicked() const
{
	GetWorld()->GetSubsystem<UGameFlowSubsystem>()->EndGames();
}

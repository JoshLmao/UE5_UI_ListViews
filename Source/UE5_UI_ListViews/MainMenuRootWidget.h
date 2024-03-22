#pragma once

#include <CoreMinimal.h>
#include "Blueprint/UserWidget.h"

#include "Interface/AnimatedVisibilityInterface.h"

#include "MainMenuRootWidget.generated.h"

UCLASS(Abstract)
class UMainMenuRootWidget : public UUserWidget, public IAnimatedVisibilityInterface
{
	GENERATED_BODY()

public:
	class UUserWidget* AnimatedVisibility_GetWidget();

protected:
	void NativePreConstruct() override;

protected:
	UPROPERTY(Transient, ScriptReadWrite, Meta = (BindWidgetAnimOptional))
	class UWidgetAnimation* AnimatedVisibility_Appear;

	UPROPERTY(Transient, ScriptReadWrite, Meta = (BindWidgetAnimOptional))
	class UWidgetAnimation* AnimatedVisibility_Disappear;
};
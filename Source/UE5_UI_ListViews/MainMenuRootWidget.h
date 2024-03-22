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
};
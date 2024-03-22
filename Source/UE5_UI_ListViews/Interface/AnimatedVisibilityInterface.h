#pragma once

#include <CoreMinimal.h>

#include "AnimatedVisibilityInterface.generated.h"

UINTERFACE(NotBlueprintable)
class UAnimatedVisibilityInterface : public UInterface
{
	GENERATED_BODY()
};

class IAnimatedVisibilityInterface
{
	GENERATED_BODY()

public:
	void AnimatedVisibility_DoAppear();
	void AnimatedVisibility_DoDisappear();

	virtual class UUserWidget* AnimatedVisibility_GetWidget() = 0; // pure virtual
};

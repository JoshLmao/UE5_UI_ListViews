#pragma once

#include <CoreMinimal.h>
#include <CoreUObject/Public/UObject/Interface.h>

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
	void AnimatedVisibility_NativePreConstruct(class UWidgetAnimation* Appear, class UWidgetAnimation* Disappear);

	void AnimatedVisibility_DoAppear();
	void AnimatedVisibility_DoDisappear();

	virtual class UUserWidget* AnimatedVisibility_GetWidget() = 0; // pure virtual

private:
	TWeakObjectPtr<class UWidgetAnimation> TransitionAppear;
	TWeakObjectPtr<class UWidgetAnimation> TransitionDisappear;
};

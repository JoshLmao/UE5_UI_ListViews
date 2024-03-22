#pragma once

#include <CoreMinimal.h>

#include <Animation/WidgetAnimationEvents.h>
#include <CoreUObject/Public/UObject/Interface.h>
#include <UMG/Public/Components/SlateWrapperTypes.h>

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

	void AnimatedVisibility_SetVisibility(const bool ShouldBeVisible);

protected:
	UFUNCTION(meta = (BlueprintProtected = true))
	virtual void OnAnimatedVisibility_TransitionAppearStarted();
	UFUNCTION(meta = (BlueprintProtected = true))
	virtual void OnAnimatedVisibility_TransitionAppearFinished();
	UFUNCTION(meta = (BlueprintProtected = true))
	virtual void OnAnimatedVisibility_TransitionDisappearStarted();
	UFUNCTION(meta = (BlueprintProtected = true))
	virtual void OnAnimatedVisibility_TransitionDisappearFinished();

private:
	void TryPlayAnimation(UWidgetAnimation* AnimationToPlay, const bool VisibilityFlag);
	void SetVisibilityInternal(const bool VisibilityFlag);

	TWeakObjectPtr<class UWidgetAnimation> TransitionAppear;
	TWeakObjectPtr<class UWidgetAnimation> TransitionDisappear;
	
	FWidgetAnimationDynamicEvent AppearStartedEvent;
	FWidgetAnimationDynamicEvent AppearFinishedEvent;
	FWidgetAnimationDynamicEvent DisappearStartedEvent;
	FWidgetAnimationDynamicEvent DisappearFinishedEvent;
};

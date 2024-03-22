#include "AnimatedVisibilityInterface.h"

#include <UMG/Public/Animation/WidgetAnimation.h>
#include <Blueprint/UserWidget.h>

void IAnimatedVisibilityInterface::AnimatedVisibility_NativePreConstruct(UWidgetAnimation* Appear, UWidgetAnimation* Disappear)
{
	if (Appear != nullptr)
	{
		TransitionAppear = Appear;
	}
	if (Disappear != nullptr)
	{
		TransitionDisappear = Disappear;
	}
}

void IAnimatedVisibilityInterface::AnimatedVisibility_DoAppear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoAppear()"), *AnimatedVisibility_GetWidget()->GetName());

	if (TransitionAppear.Get())
	{
		AnimatedVisibility_SetVisibility(true);
	}
}

void IAnimatedVisibilityInterface::AnimatedVisibility_DoDisappear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoDisappear()"), *AnimatedVisibility_GetWidget()->GetName());

	if (TransitionDisappear.Get())
	{
		AnimatedVisibility_SetVisibility(false);
	}
}

void IAnimatedVisibilityInterface::AnimatedVisibility_SetVisibility(const bool ShouldBeVisible)
{
	// checkf(AnimatedVisibility_CanAnimate(), TEXT("Need to have appear and/or disappear animation"));

	const ESlateVisibility& WidgetVisibility = AnimatedVisibility_GetWidget()->GetVisibility();
	const bool IsCurrentlyVisible = WidgetVisibility == ESlateVisibility::HitTestInvisible || WidgetVisibility == ESlateVisibility::SelfHitTestInvisible;
	const bool IsPlayingAppear = AnimatedVisibility_GetWidget()->IsAnimationPlaying(TransitionAppear.Get());
	const bool IsPlayingDisappear = AnimatedVisibility_GetWidget()->IsAnimationPlaying(TransitionDisappear.Get());

	if ((IsCurrentlyVisible == false || IsPlayingDisappear) && ShouldBeVisible == true)
	{
		TryPlayAnimation(TransitionAppear.Get(), true);
	}
	else if ((IsCurrentlyVisible == true || IsPlayingAppear) && ShouldBeVisible == false)
	{
		TryPlayAnimation(TransitionDisappear.Get(), false);
	}
}

void IAnimatedVisibilityInterface::TryPlayAnimation(UWidgetAnimation* AnimationToPlay, const bool VisibilityFlag)
{
	if (AnimationToPlay == nullptr)
	{
		SetVisibilityInternal(VisibilityFlag);
		return;
	}
	if (!AnimatedVisibility_GetWidget()->IsAnimationPlaying(AnimationToPlay))
	{
		AnimatedVisibility_GetWidget()->StopAllAnimations();
		AnimatedVisibility_GetWidget()->PlayAnimationForward(AnimationToPlay);
	}
}

void IAnimatedVisibilityInterface::SetVisibilityInternal(const bool VisibilityFlag)
{
	AnimatedVisibility_GetWidget()->SetVisibility(VisibilityFlag ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
}


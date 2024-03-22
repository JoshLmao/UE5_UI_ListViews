#include "AnimatedVisibilityInterface.h"

#include <UMG/Public/Animation/WidgetAnimation.h>
#include <UMG/Public/Blueprint/UserWidget.h>
#include <UMG/Public/Blueprint/WidgetTree.h>

void IAnimatedVisibilityInterface::AnimatedVisibility_NativePreConstruct(UWidgetAnimation* Appear, UWidgetAnimation* Disappear)
{
	if (Appear != nullptr)
	{
		TransitionAppear = Appear;

		AppearStartedEvent.BindUFunction(AnimatedVisibility_GetWidget(), GET_FUNCTION_NAME_CHECKED(IAnimatedVisibilityInterface, OnAnimatedVisibility_TransitionAppearStarted));
		AnimatedVisibility_GetWidget()->BindToAnimationStarted(TransitionAppear.Get(), AppearStartedEvent);

		AppearFinishedEvent.BindUFunction(AnimatedVisibility_GetWidget(), GET_FUNCTION_NAME_CHECKED(IAnimatedVisibilityInterface, OnAnimatedVisibility_TransitionAppearFinished));
		AnimatedVisibility_GetWidget()->BindToAnimationFinished(TransitionAppear.Get(), AppearFinishedEvent);
	}
	if (Disappear != nullptr)
	{
		TransitionDisappear = Disappear;

		DisappearStartedEvent.BindUFunction(AnimatedVisibility_GetWidget(), GET_FUNCTION_NAME_CHECKED(IAnimatedVisibilityInterface, OnAnimatedVisibility_TransitionDisappearStarted));
		AnimatedVisibility_GetWidget()->BindToAnimationStarted(TransitionDisappear.Get(), DisappearStartedEvent);

		DisappearFinishedEvent.BindUFunction(AnimatedVisibility_GetWidget(), GET_FUNCTION_NAME_CHECKED(IAnimatedVisibilityInterface, OnAnimatedVisibility_TransitionDisappearFinished));
		AnimatedVisibility_GetWidget()->BindToAnimationFinished(TransitionDisappear.Get(), DisappearFinishedEvent);
	}
}

void IAnimatedVisibilityInterface::AnimatedVisibility_DoAppear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoAppear()"), *AnimatedVisibility_GetWidget()->GetName());

	AnimatedVisibility_GetWidget()->WidgetTree->ForEachWidget(
		[](UWidget* Widget)
		{
			if (Widget->Implements<UAnimatedVisibilityInterface>())
			{
				auto* AnimatedVisibilityWidget = Cast<IAnimatedVisibilityInterface>(Widget);
				AnimatedVisibilityWidget->AnimatedVisibility_DoAppear();
			}
		});

	if (TransitionAppear.Get())
	{
		AnimatedVisibility_SetVisibility(true);
	}
}

void IAnimatedVisibilityInterface::AnimatedVisibility_DoDisappear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoDisappear()"), *AnimatedVisibility_GetWidget()->GetName());

	AnimatedVisibility_GetWidget()->WidgetTree->ForEachWidget(
		[](UWidget* Widget)
		{
			if (Widget->Implements<UAnimatedVisibilityInterface>())
			{
				auto* AnimatedVisibilityWidget = Cast<IAnimatedVisibilityInterface>(Widget);
				AnimatedVisibilityWidget->AnimatedVisibility_DoDisappear();
			}
		});

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

void IAnimatedVisibilityInterface::OnAnimatedVisibility_TransitionAppearStarted()
{
}

void IAnimatedVisibilityInterface::OnAnimatedVisibility_TransitionAppearFinished()
{
}

void IAnimatedVisibilityInterface::OnAnimatedVisibility_TransitionDisappearStarted()
{
}

void IAnimatedVisibilityInterface::OnAnimatedVisibility_TransitionDisappearFinished()
{
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


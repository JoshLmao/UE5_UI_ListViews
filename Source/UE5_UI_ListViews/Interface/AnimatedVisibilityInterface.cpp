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
}

void IAnimatedVisibilityInterface::AnimatedVisibility_DoDisappear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoDisappear()"), *AnimatedVisibility_GetWidget()->GetName());
}

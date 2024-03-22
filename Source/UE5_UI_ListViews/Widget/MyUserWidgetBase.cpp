#include "MyUserWidgetBase.h"

UUserWidget* UMyUserWidgetBase::AnimatedVisibility_GetWidget()
{
    return this;
}

void UMyUserWidgetBase::NativePreConstruct()
{
    Super::NativePreConstruct();

    AnimatedVisibility_NativePreConstruct(AnimatedVisibility_Appear, AnimatedVisibility_Disappear);
}


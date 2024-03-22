#include "MainMenuRootWidget.h"

UUserWidget* UMainMenuRootWidget::AnimatedVisibility_GetWidget()
{
    return this;
}

void UMainMenuRootWidget::NativePreConstruct()
{
    Super::NativePreConstruct();

    AnimatedVisibility_NativePreConstruct(AnimatedVisibility_Appear, AnimatedVisibility_Disappear);
}

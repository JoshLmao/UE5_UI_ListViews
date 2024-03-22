#include "AnimatedVisibilityInterface.h"

#include <Blueprint/UserWidget.h>

void IAnimatedVisibilityInterface::AnimatedVisibility_DoAppear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoAppear()"), *AnimatedVisibility_GetWidget()->GetName());
}

void IAnimatedVisibilityInterface::AnimatedVisibility_DoDisappear()
{
	UE_LOG(LogTemp, Log, TEXT("Widget %s: AnimatedVisibility_DoDisappear()"), *AnimatedVisibility_GetWidget()->GetName());
}

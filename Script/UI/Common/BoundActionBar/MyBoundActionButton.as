UCLASS(Abstract)
class UAS_MyBoundActionButton : UCommonBoundActionButton
{
	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		Text_ActionName.AutoWrapText = true;
	}
}
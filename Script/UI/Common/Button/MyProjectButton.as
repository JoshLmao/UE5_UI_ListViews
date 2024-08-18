UCLASS(Abstract)
class UAS_MyProjectButton : UCommonButtonBase
{
	UFUNCTION(BlueprintOverride)
	void PreConstruct(bool IsDesignTime)
	{
		Text.AutoWrapText = true;
	}

	void SetText(FText InText)
	{
		Text.SetText(InText);
	}

	UPROPERTY(BindWidget)
	private UCommonTextBlock Text;
}
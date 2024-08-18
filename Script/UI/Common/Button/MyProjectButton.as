UCLASS(Abstract)
class UAS_MyProjectButton : UCommonButtonBase
{
	void SetText(FText InText)
	{
		Text.SetText(InText);
	}

	UPROPERTY(BindWidget)
	private UCommonTextBlock Text;
}
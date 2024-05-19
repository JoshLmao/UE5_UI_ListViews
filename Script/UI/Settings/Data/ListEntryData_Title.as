UCLASS()
class UAS_ListEntryData_Title : UAS_ListEntryDataBase
{
	FText GetTitle()
	{
		return TitleText;
	}

	void SetTitle(FText InTitleText)
	{
		TitleText = InTitleText;
	}

	private FText TitleText;
}
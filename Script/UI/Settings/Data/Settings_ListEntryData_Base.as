/*
	Base implementation and properties needed across all Settings list entries
*/
UCLASS(Abstract)
class UAS_Settings_ListEntryData_Base : UAS_ListEntryDataBase
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
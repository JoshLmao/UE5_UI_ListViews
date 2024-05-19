/*
	List Entry Data Class:
	A carousel of options to allow the user to choose which option out of a range of options
*/
UCLASS()
class UAS_Settings_ListEntryData_Carousel : UAS_Settings_ListEntryData_Base
{
	TArray<FText> GetOptions()
	{
		return CarouselOptions;
	}

	void SetOptions(TArray<FText> InOptions)
	{
		CarouselOptions = InOptions;
	}

	private TArray<FText> CarouselOptions;
}
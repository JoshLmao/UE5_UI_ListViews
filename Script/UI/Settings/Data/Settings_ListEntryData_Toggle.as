/*
	List Entry Data Class:
	Simple toggle which can only be enabled or disabled (true or false)
*/
UCLASS()
class UAS_Settings_ListEntryData_Toggle : UAS_Settings_ListEntryData_Base
{
	bool GetToggleStatus()
	{
		return ToggleStatus;
	}

	void SetToggleStatus(bool InStatus)
	{
		ToggleStatus = InStatus;
	}

	private bool ToggleStatus;
}
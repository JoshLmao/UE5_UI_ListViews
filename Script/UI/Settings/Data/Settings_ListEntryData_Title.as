/*
	List Entry Data Class:
	A basic title list entry. The entire entry doesn't have any custom properties, just using Title from `UAS_Settings_ListEntryData_Base`
*/
UCLASS()
class UAS_Settings_ListEntryData_Title : UAS_Settings_ListEntryData_Base
{
	// Override default value, title shouldn't be selectable
	default IsSelectable = false;
}
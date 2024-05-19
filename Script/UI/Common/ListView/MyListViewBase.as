/*
	List View base:
	Base implementation for all List Views to use. Contains sensible defaults
*/
UCLASS(Abstract)
class UAS_MyListViewBase : UMyListViewBase
{
	default VerticalEntrySpacing = 16.0f;
}
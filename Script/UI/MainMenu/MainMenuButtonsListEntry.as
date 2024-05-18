UCLASS(Abstract)
class UAS_MainMenuButtonsListEntry : UAS_MyListEntryBase
{
	UPROPERTY(BindWidget)
	private UButton Button;

	UPROPERTY(BindWidget)
	private UTextBlock TextBlock;

	UFUNCTION(BlueprintOverride)
	void NativeOnListItemObjectSet(UObject ListItemObject)
	{
	}
}
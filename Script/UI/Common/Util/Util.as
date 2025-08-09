namespace Util
{
AMainMenuHUD GetMainMenuHUD(APlayerController Controller)
{
	return Cast<AMainMenuHUD>(Controller.GetHUD());
}
} // namespace Util
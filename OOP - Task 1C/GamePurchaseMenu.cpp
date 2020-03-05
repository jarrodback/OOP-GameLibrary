#include "GamePurchaseMenu.h"

GamePurchaseMenu::GamePurchaseMenu(const std::string& title, Application* app, const int& gameID) : Menu(title, app), gameID(gameID)
{
	Paint();
}

void GamePurchaseMenu::OutputOptions()
{
	Line("Description: " + app->GetStore().GetGames()[gameID]->GetDescription());
	Line();
	Line("Price " + std::to_string((app->GetStore().GetGames()[gameID]->GetCost() / 100))); //Needs Formatting.
	if (app->IsUserLoggedIn()) {
		Line();
		Option('P', "Purchase Game");
	}
}

bool GamePurchaseMenu::HandleChoice(char choice)
{
	return false;
}

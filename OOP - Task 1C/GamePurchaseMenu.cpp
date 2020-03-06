#include "GamePurchaseMenu.h"

GamePurchaseMenu::GamePurchaseMenu(const std::string& title, Application* app, const int& gameID) : Menu(title, app), gameID(gameID)
{
	Paint();
}

void GamePurchaseMenu::OutputOptions()
{
	Game* game = app->GetStore().GetGames()[gameID];
	bool inLibrary = false;
	Line("Description: " + game->GetDescription());
	Line();
	Line("Price " + std::to_string((app->GetStore().GetGames()[gameID]->GetCost()))); //Needs Formatting.
	if (app->IsUserLoggedIn()) {
		Line();
		Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
		for (int i = 0; i < player->GetLibrary().size(); ++i) {
			if (player->GetLibrary()[i]->GetName() == game->GetName())
				inLibrary = true;
		}
		if (!inLibrary) {	
			Option('P', "Purchase Game");
		}
		else {
			for (int i = 0; i < player->GetLibrary().size(); ++i) {
				if (player->GetLibrary()[i]->GetName() == game->GetName()) {
					Line("Time Played: " + Utils::formatGametime(player->GetLibrary()[i]->getMinutesPlayed()));
					Line("Purchased on: " + std::to_string(player->GetLibrary()[i]->GetDate().getDay()) + "-" + std::to_string(player->GetLibrary()[i]->GetDate().getMonth()) + "-" + std::to_string(player->GetLibrary()[i]->GetDate().getYear()));
				}
			}
				
		}
	}
}

bool GamePurchaseMenu::HandleChoice(char choice)
{
	if (app->IsUserLoggedIn()) {
		Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
		Game* game = app->GetStore().GetGames()[gameID];
		bool inLibrary = false;
		switch (choice) {
			case 'P':
				for (int i = 0; i < player->GetLibrary().size(); ++i) {
					if (player->GetLibrary()[i]->GetName() == game->GetName())
						inLibrary = true;
				}
				if (player->getCredits() >= game->GetCost() && !inLibrary)  {
					player->deductCredits(game->GetCost());
					player->AddToLibrary(new LibraryItem(Date::CurrentDate(), game));
				}
			break;
		}
	}

	return false;
}

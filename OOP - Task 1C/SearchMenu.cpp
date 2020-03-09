#include "SearchMenu.h"

SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
	filteredGames = app->GetStore().GetGames();
	Paint();
}

void SearchMenu::OutputOptions()
{
	Line("Searching ", " Games.", filteredGames.length());
	Line();
	if (filteredGames.length() > 0) {
		if (app->IsUserLoggedIn() && !app->IsUserGuest()) {
			Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
			Line("Credits: " + std::to_string(player->getCredits())); //Needs formatting.
			Line();
			for (int i = 0; i < filteredGames.length(); i++)
			{
				bool found = false;
				for (int x = 0; x < player->GetLibrary().size(); x++) {
					if (player->GetLibrary()[x]->GetName() == filteredGames[i]->GetName())
						found = true;
				}
				if (found) Option(i + 1, filteredGames[i]->GetName() + " (purchased)");
				else Option(i + 1, filteredGames[i]->GetName());
			}
		} else {
			if (app->IsUserGuest())
				Line("You must be a registered user to buy from the store.");
			else
				Line("You must login to purchase.");
			Line();
			for (int i = 0; i < filteredGames.length(); i++)
			{
				// adding 1 so the display is nicer for the user
				Option(i + 1, filteredGames[i]->GetName());
			}
		}
		Line();
	}
	else {
		Line("No results found.");
		Line();
	}
	Option('N', "Search by Name");
	Option('P', "Search by Price");
}

bool SearchMenu::HandleChoice(char choice)
{
	switch (choice) {
		case 'N': {
			std::string search = Question("Enter the name of the game");
			for (int i = filteredGames.length(); i > 0; --i) 
				if (!Utils::startsWith(search, filteredGames[i - 1]->GetName())) 
					filteredGames.deleteOne(filteredGames[i - 1]);
		} break;
		case 'P': {
			std::string priceRange = Question("Enter a price range (e.g. 5-10)");
			for (int i = filteredGames.length(); i > 0; --i) 
				if (!Utils::inPriceRange(priceRange, app->GetStore().GetGames()[i - 1]->GetCost())) 
					filteredGames.deleteOne(filteredGames[i - 1]);
		} break;		
	}

	if (filteredGames.length() > 0) {
		int index = choice - '1';
		if (index >= 0 && index < filteredGames.length())
		{
			std::string gameTitle = filteredGames[index]->GetName();
			GamePurchaseMenu(gameTitle, app, index);
		}
	}
	return false;
}

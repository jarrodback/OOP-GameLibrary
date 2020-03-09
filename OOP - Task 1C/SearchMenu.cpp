#include "SearchMenu.h"

SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
	filteredGames = app->GetStore().GetGames();
	Paint();
}

void SearchMenu::OutputOptions()
{
	std::stringstream stream;
	stream << std::fixed << std::setprecision(0) << filteredGames.length();
	Line("Searching " + stream.str() + " Games.");
	Line();
	if (filteredGames.length() > 0) {
		if (app->IsUserLoggedIn() && !app->IsUserGuest()) {
			Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
			std::stringstream stream;
			stream << std::fixed << std::setprecision(2) << player->getCredits() / 100;
			Line("Credits: " + stream.str()); //Needs formatting.
			Line();
			for (int i = 0; i < filteredGames.length(); i++)
			{
				bool found = false;
				for (int x = 0; x < player->GetLibrary().size(); x++) {
					if (player->GetLibrary()[x]->GetName() == filteredGames[i]->GetName())
						found = true;
				}
				if (found) {
					std::stringstream stream;
					stream << filteredGames[i]->GetName() << " (Rating: " << std::fixed << std::setprecision(0) << filteredGames[i]->calculateRating() << "%) - Purchased";
					Option(i + 1, stream.str());
				}
				else {
					std::stringstream stream;
					stream << filteredGames[i]->GetName() << " (Rating: " << std::fixed << std::setprecision(0) << filteredGames[i]->calculateRating() << "%)";
					Option(i + 1, stream.str());
				}
			}
		} else {
			if (app->IsUserGuest())
				Line("You must be a registered user to buy from the store.");
			else
				Line("You must login to purchase.");
			Line();
			for (int i = 0; i < filteredGames.length(); i++)
			{
				std::stringstream stream;
				stream << filteredGames[i]->GetName() << " (Rating: " << std::fixed << std::setprecision(0) << filteredGames[i]->calculateRating() << "%)";
				Option(i + 1, stream.str());
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

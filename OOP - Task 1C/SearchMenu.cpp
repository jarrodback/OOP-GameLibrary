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
		for (int i = 0; i < filteredGames.length(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, filteredGames[i]->GetName());
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
			Line("Enter the name of the game: ");
			std::string search = Utils::GetLineFromUser();
			for (int i = filteredGames.length(); i > 0; --i) {
				if (!Utils::startsWith(search, filteredGames[i - 1]->GetName())) {
					filteredGames.deleteOne(filteredGames[i - 1]);
				}
			}
		} break;
		case 'P': {
			Line("Enter a price range (e.g. 5-10): ");
			std::string priceRange = Utils::GetLineFromUser();
			for (int i = filteredGames.length(); i > 0; --i) {
				if (!Utils::inPriceRange(priceRange, app->GetStore().GetGames()[i - 1]->GetCost())) {
					filteredGames.deleteOne(filteredGames[i - 1]);
				}
			}
		} break;		
	}
	return false;
}

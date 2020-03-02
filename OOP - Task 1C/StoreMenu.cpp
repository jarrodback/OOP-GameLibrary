#include "StoreMenu.h"

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	Line("Credits: ");
	Line();
	for (int i = 0; i < games.size(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, games[i]);
	}
	Line();
	Option('S', "Search via Name");
	Option('P', "Search via Price");
}

bool StoreMenu::HandleChoice(char choice)
{
	switch (choice) {
		case 'S':{
			std::vector<std::string> results;
			Line("Enter the name of the game: ");
			std::string search = Utils::GetLineFromUser();
			for (std::string nameOfGame : games) {
				if (Utils::startsWith(search, nameOfGame)) {
					results.push_back(nameOfGame);
				}
			}
			displayResults(results);
		} break;
		case 'P': {
			std::vector<std::string> results;
			Line("Enter a price range i.e 500-1000: ");
			std::string priceRange = Utils::GetLineFromUser();
			for (int i = 0; i < app->GetStore().games.length(); ++ i) {
				if (Utils::inPriceRange(priceRange, app->GetStore().games[i]->GetCost())) {
					results.push_back(app->GetStore().games[i]->GetName());
				}
			}
			displayResults(results);
		} break;
	} 
	if ((choice - 1) >= 0 && (choice - 1) < games.size()) {

	}

	return false;
}

void StoreMenu::displayResults(std::vector<std::string> results) {
	system("CLS");
	if (results.size() > 0) {
		Line(results.size() + " new result(s)");
		for (int i = 0; i < results.size(); ++i)
			Option(i + 1, results[i]);
		Line();
		Option('S', "Search by Name");
		Option('P', "Search by Price");
		Option('B', "Back");
		Utils::GetCharFromUser();
	}
	else {
		Line("No results found.");
		Line();
		Option('S', "Search by Name");
		Option('P', "Search by Price");
		Option('B', "Back");
		Utils::GetCharFromUser();
	}
}
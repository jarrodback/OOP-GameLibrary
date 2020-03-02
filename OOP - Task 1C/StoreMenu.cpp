#include "StoreMenu.h"
#include <algorithm>
StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
	filteredGames = app->GetStore().GetGames();
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	Line("Credits: ");
	Line();
	for (int i = 0; i < filteredGames.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, filteredGames[i]->GetName());
	}
	Line();
	Option('S', "Search via Name");
	Option('P', "Search via Price");
}

bool StoreMenu::HandleChoice(char choice)
{
	switch (choice) {
		case 'S':{
			Line("Enter the name of the game: ");
			std::string search = Utils::GetLineFromUser();
			for (int i = filteredGames.length(); i > 0; --i){
				if (!Utils::startsWith(search, filteredGames[i - 1]->GetName())) {
					filteredGames.deleteOne(filteredGames[i -1]);
				}
			}
		} break;
		case 'P': {
			Line("Enter a price range i.e 5-10: ");
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

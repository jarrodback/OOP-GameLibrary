#include "StoreMenu.h"
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
	if (filteredGames.length() == 0) {
		Line("No results found.");
	}
	else {		
		for (int i = 0; i < filteredGames.length(); i++)
		{
			// adding 1 so the display is nicer for the user
			Option(i + 1, filteredGames[i]->GetName());
		}
		Line();
		Option('S', "Search store");
	}
}

bool StoreMenu::HandleChoice(char choice)
{
	switch (choice) {
		case 'S': {
			SearchMenu("SEARCH THE STORE", app);
		} break;
	} 

	return false;
}

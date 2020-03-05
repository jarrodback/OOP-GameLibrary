#include "StoreMenu.h"
StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
	Player* player = dynamic_cast<Player*>(app->GetCurrentUser());
	if (player != nullptr) {
		Line("Credits: " + std::to_string(player->getCredits() / 100));
	}
	else
		Line("You must login to purchase.");
	Line();	
	for (int i = 0; i < app->GetStore().GetGames().length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, app->GetStore().GetGames()[i]->GetName());
	}
	Line();
	Option('S', "Search store");
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

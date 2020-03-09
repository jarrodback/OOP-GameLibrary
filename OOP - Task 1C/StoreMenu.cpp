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
	if (app->IsUserLoggedIn() && !app->IsUserGuest()) {
		if(player){
			Line("Credits: " + std::to_string(player->getCredits())); //Needs formatting.
			Line();
			for (int i = 0; i < app->GetStore().GetGames().length(); i++){
				bool found = false;
				for (int x = 0; x < player->GetLibrary().size(); x++){
					if (player->GetLibrary()[x]->GetName() == app->GetStore().GetGames()[i]->GetName())
						found = true;				
				}
			}
			if (found) Option(i + 1, "(purchased) " + app->GetStore().GetGames()[i]->GetName() +" (Rating: " + std::to_string(app->GetStore().GetGames()[i]->calculateRating()) + "%)");
			else Option(i + 1, app->GetStore().GetGames()[i]->GetName() + " (Rating: " + std::to_string(app->GetStore().GetGames()[i]->calculateRating()) + "%)");
		}
	}
	else {
		if (app->IsUserGuest())
			Line("You must be a registered user to buy from the store.");
		else
			Line("You must login to purchase.");
		Line();
		for (int i = 0; i < app->GetStore().GetGames().length(); i++)
			Option(i + 1, app->GetStore().GetGames()[i]->GetName() + " (Rating: " + std::to_string(app->GetStore().GetGames()[i]->calculateRating()) + "%)");
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

	int index = choice - '1';
	if (index >= 0 && index < app->GetStore().GetGames().length())
	{
		std::string gameTitle = app->GetStore().GetGames()[index]->GetName();
		GamePurchaseMenu(gameTitle, app, index);
	}

	return false;
}

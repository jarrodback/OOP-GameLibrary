#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Player* pPlayer = (Player*)app->GetCurrentUser();
	Line("Credits: " + std::to_string(pPlayer->getCredits()));
	Line("PURCHASE CREDITS");
	Option('I', "Purchase 1 credit.");
	Option('O', "Purchase 10 credits.");
	Option('P', "Purchase 100 credits.");
	Line();
	Line("GAMES");
	
	for (int x = 0; x < pPlayer->GetLibrary().length(); x++) {
		Option(x + 1, pPlayer->GetLibrary()[x]->GetName());
	}

	if (app->IsUserAdmin()) {
		Line();
		Line("ADMIN");
		Option('A', "Create Player");
		Option('R', "Remove Player");
	}
}

bool ProfileMenu::HandleChoice(char choice)
{
	Player* player = (Player*)app->GetCurrentUser();
	switch (choice) {
	case 'A': {
		Line("Please enter a username: ");
		std::string username = Utils::GetLineFromUser();
		Line("Please enter a password: ");
		std::string password = Utils::GetLineFromUser();
		app->GetCurrentAccount()->AddToUsers(new User(username, password, Date::CurrentDate()));
	}break;
	case 'R': {
		RemoveUserMenu("Remove User From Account", app);
	}break;
	case 'I': {
		player->addCredits(1);
	}break;
	case 'O': {
		player->addCredits(10);
	}break;
	case 'P': {
		player->addCredits(100);
	}break;
	}
	return false;
}

#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Line("GAMES");
	Player* pPlayer = (Player*)app->GetCurrentUser();
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
	}
	return false;
}

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
	Line();
	Option('V', "Rate a Game");
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
	case 'V': {
		Line("Select a game to rate: ");
		Player* pPlayer = dynamic_cast<Player*>(app->GetCurrentUser());
		int index = Utils::GetCharFromUser() - '1';
		if (index >= 0 && index < pPlayer->GetLibrary().length())
		{
			Option('L', "Like");
			Option('D', "Dislike");
			Line();
			char choice = Utils::GetCharFromUser();
			if (choice == 'L') {
				for (int i = 0; i < app->GetStore().GetGames().length(); ++i)
					if (app->GetStore().GetGames()[i]->GetName() == pPlayer->GetLibrary()[index]->GetName())
						app->GetStore().GetGames()[i]->addLike();
			}
			else if (choice == 'D') {
				for (int i = 0; i < app->GetStore().GetGames().length(); ++i)
					if (app->GetStore().GetGames()[i]->GetName() == pPlayer->GetLibrary()[index]->GetName())
						app->GetStore().GetGames()[i]->addDislike();
			}
				
		}
	}
	}
	return false;
}

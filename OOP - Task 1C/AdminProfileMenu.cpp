#include "AdminProfileMenu.h"
#include "RemoveUserMenu.h"

AdminProfileMenu::AdminProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void AdminProfileMenu::OutputOptions()
{
	Option('A', "Create Player");
	Option('R', "Remove Player");
	Line();
	Line("GUEST SETTINGS");
	Option('X', "Add Game to Guest Library");
	Option('Z', "Remove Game from Guest Library");
}

bool AdminProfileMenu::HandleChoice(char choice)
{
	Player* player = (Player*)app->GetCurrentUser();

	switch (choice) {
	case 'A': {
		std::string username = Question("Please enter a username");
		std::string password = Question("Please enter a password");
		app->GetCurrentAccount()->AddToUsers(new Player(username, password, Date::CurrentDate(), 0));
	}break;

	case 'R': {
		RemoveUserMenu("Remove User From Account", app);
	}break;
	case 'X': {
		std::string choice = Question("Enter the ID of the game you wish to add");
		int index = stoi(choice) - 1;
		if (index >= 0 && index < player->GetLibrary().size() && player->DoesLibraryContain(player->GetLibrary()[index]))
			app->GetCurrentAccount()->GetGuest()->AddToLibrary(player->GetLibrary()[index]);
	}break;
	case 'Z': {
		std::string choice = Question("Enter the ID of the game you wish to remove");
		int index = stoi(choice) - 1;
		if (index >= 0 && index < player->GetLibrary().size() && index < app->GetCurrentAccount()->GetGuest()->GetLibrary().size())
			if (player->DoesLibraryContain(app->GetCurrentAccount()->GetGuest()->GetLibrary()[index]))
				app->GetCurrentAccount()->GetGuest()->RemoveFromLibrary(player->GetLibrary()[index]);

	}break;
	}
	return false;
}
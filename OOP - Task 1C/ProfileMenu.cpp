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
	if (sortedList.size() == 0) {
		Player* pPlayer = (Player*)app->GetCurrentUser();
		for (int x = 0; x < pPlayer->GetLibrary().size(); x++) {
			Option(x + 1, pPlayer->GetLibrary()[x]->GetName());
		}
	}
	Line();
	Option('V', "Rate a Game");

	Line();
	Line("SORT BY");
	Option('N', "Sort by Name");
	Option('D', "Sort by Date Purchased");


	if (app->IsUserAdmin()) {
		Line();
		Line("ADMIN");
		Option('A', "Create Player");
		Option('R', "Remove Player");
	}
	else {
		for (int x = 0; x < sortedList.size(); x++) {
			Option(x + 1, sortedList[x]->GetName());
		}
	}
}
bool SortByDates(LibraryItem* li, LibraryItem* li2) {
	return (li->GetDate() < li2->GetDate());
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
	case 'V': {
		Line("Select a game to rate: ");
		Player* pPlayer = dynamic_cast<Player*>(app->GetCurrentUser());
		int index = Utils::GetCharFromUser() - '1';
		if (index >= 0 && index < pPlayer->GetLibrary().size())
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
	}break;

	case 'N': {
		Player* pPlayer = (Player*)app->GetCurrentUser();
		sortedList = pPlayer->GetLibrary();
		std::sort(sortedList.begin(), sortedList.end());
	}break;

	case 'D': {
		Player* pPlayer = (Player*)app->GetCurrentUser();
		sortedList = pPlayer->GetLibrary();
		std::sort(sortedList.begin(), sortedList.end(), SortByDates);
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

#include "ProfileMenu.h"


ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Player* pPlayer = dynamic_cast<Player*>(app->GetCurrentUser());
	if (pPlayer) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << pPlayer->getCredits() / 100;
		Line("Credits: " + stream.str()); //Needs formatting.
		Line("PURCHASE CREDITS");
		Option('I', "Purchase 1 credit.");
		Option('O', "Purchase 10 credits.");
		Option('P', "Purchase 100 credits.");
		Line();
	}
	Line("GAMES");

	if (sortedList.size() == 0) {
		if (pPlayer->GetLibrary().size() == 0) {
			Line("No Games in library.");
		}
		else {
			for (int x = 0; x < pPlayer->GetLibrary().size(); x++) {
				Option(x + 1, pPlayer->GetLibrary()[x]->GetName() + " - Playtime: " + Utils::formatGametime(pPlayer->GetLibrary()[x]->getMinutesPlayed()));
			}
		}

	}else {
		for (int x = 0; x < sortedList.size(); x++) {
			Option(x + 1, sortedList[x]->GetName() + " - Playtime: " + Utils::formatGametime(sortedList[x]->getMinutesPlayed()));
		}
	}
	if (pPlayer && pPlayer->GetLibrary().size() > 0) {
		Line();
		Option('V', "Rate a Game");
	}
	Line();
	Line("SORT BY");
	Option('N', "Sort by Name");
	Option('D', "Sort by Date Purchased");

	if (app->IsUserAdmin()) {
		Line();
		Line("ADMIN");
		Option('A', "Create Player");
		Option('R', "Remove Player");
		Line();
		Line("GUEST SETTINGS");
		Option('X', "Add Game to Guest Library");
		Option('Z', "Remove Game from Guest Library");
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
bool SortByName(LibraryItem* li, LibraryItem* li2) {
	return (li->GetName() < li2->GetName());
}
bool ProfileMenu::HandleChoice(char choice)
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
	case 'V': {
		Player* pPlayer = dynamic_cast<Player*>(app->GetCurrentUser());
		if (pPlayer && pPlayer->GetLibrary().size() > 0) {
			Line("Select a game to rate: ");
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
		}
	}break;

	case 'N': {
		Player* pPlayer = dynamic_cast<Player*>(app->GetCurrentUser());
		Guest* pGuest = dynamic_cast<Guest*>(app->GetCurrentUser());
		if (pPlayer)
			sortedList = pPlayer->GetLibrary();
		else if (pGuest)
			sortedList = pGuest->GetLibrary();
		std::sort(sortedList.begin(), sortedList.end(), SortByName);
	}break;

	case 'D': {
		Player* pPlayer = dynamic_cast<Player*>(app->GetCurrentUser());
		Guest* pGuest = dynamic_cast<Guest*>(app->GetCurrentUser());
		if (pPlayer)
			sortedList = pPlayer->GetLibrary();
		else if (pGuest)
			sortedList = pGuest->GetLibrary();
		std::sort(sortedList.begin(), sortedList.end(), SortByDates);
	}break;
	case 'X': {
		std::string choice = Question("Enter the ID of the game you wish to add");
		int index = stoi(choice) - 1;
		if (index >= 0 && index < player->GetLibrary().size())
			app->GetCurrentAccount()->GetGuest()->AddToLibrary(player->GetLibrary()[index]);
	}break;
	case 'Z': {
		std::string choice = Question("Enter the ID of the game you wish to remove");
		int index = stoi(choice) - 1;
		if (index >= 0 && index < player->GetLibrary().size())
			app->GetCurrentAccount()->GetGuest()->RemoveFromLibrary(player->GetLibrary()[index]);
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

	int index = choice - '1';
	if (index >= 0 && index < player->GetLibrary().size())
	{
		player->GetLibrary()[index]->addMinutesPlayed(Utils::generateGametime());
	}
	return false;
}

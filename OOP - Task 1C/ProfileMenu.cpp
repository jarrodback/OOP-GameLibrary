#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Line("GAMES");
	Player* pPlayer = (Player*)app->GetCurrentUser();
	for (int x = 0; x < pPlayer->library.length(); x++) {
		Option(x + 1, pPlayer->library[x]->GetName());
	}
}

bool ProfileMenu::HandleChoice(char choice)
{
	return false;
}

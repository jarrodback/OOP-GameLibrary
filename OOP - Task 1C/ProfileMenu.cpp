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

	if (app->IsUserAdmin()) {
		Line();
		Line("ADMIN");
		Option(1, "Create Player");
		Option(2, "Remove Player");
	}
}

bool ProfileMenu::HandleChoice(char choice)
{
	return false;
}

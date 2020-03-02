#include "RemoveUserMenu.h"

RemoveUserMenu::RemoveUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void RemoveUserMenu::OutputOptions()
{
	for (int x = 0; x < app->GetCurrentAccount()->users.length(); x++) {
		if (app->GetCurrentAccount()->users[x] != app->GetCurrentUser())
			Option(x + 1, app->GetCurrentAccount()->users[x]->GetUsername());
	}
}

bool RemoveUserMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	if (index >= 0 && index < app->GetCurrentAccount()->users.length() && app->GetCurrentUser() != app->GetCurrentAccount()->users[index]) {
		app->GetCurrentAccount()->users.deleteOne(app->GetCurrentAccount()->users[index]);
	}
	return false;
}
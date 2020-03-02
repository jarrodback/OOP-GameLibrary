#include "RemoveUserMenu.h"

RemoveUserMenu::RemoveUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void RemoveUserMenu::OutputOptions()
{
	for (int x = 0; x < app->GetCurrentAccount()->GetUsers().length(); x++) {
		if (app->GetCurrentAccount()->GetUsers()[x] != app->GetCurrentUser())
			Option(x + 1, app->GetCurrentAccount()->GetUsers()[x]->GetUsername());
	}
}

bool RemoveUserMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	if (index >= 0 && index < app->GetCurrentAccount()->GetUsers().length() && app->GetCurrentUser() != app->GetCurrentAccount()->GetUsers()[index]) {
		app->GetCurrentAccount()->RemoveFromUsers(app->GetCurrentAccount()->GetUsers()[index]);
	}
	return false;
}
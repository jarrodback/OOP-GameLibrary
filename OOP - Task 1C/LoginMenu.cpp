#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title,app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn()) {
		for (int x = 0; x < app->GetCurrentAccount()->users.length(); x++) {
			Option(x + 1, app->GetCurrentAccount()->users[x]->GetUsername());
		}
	}
	else {
		for (int x = 0; x < app->accounts.length(); x++) {
			Option(x + 1, app->accounts[x]->getEmail());
		}
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	if (app->IsAccountLoggedIn()) {
		if (index >= 0 && index < app->GetCurrentAccount()->users.length())
		{
			Line("Enter the password: ");
			std::string password = Utils::GetLineFromUser();
			if (app->GetCurrentAccount()->users[index]->CheckPassword(password)) {
				app->LoginUser(app->GetCurrentAccount()->users[index]);
				return true;
			}
		}
	}
	else {
		if (index >= 0 && index < app->accounts.length())
		{
			Line("Enter the password: ");
			std::string password = Utils::GetLineFromUser();
			if (app->accounts[index]->CheckPassword(password)) {
				app->LoginAccount(app->accounts[index]);
				return true;
			}
		}
	}
	return false;
}

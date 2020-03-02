#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title,app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn()) {
		for (int x = 0; x < app->GetCurrentAccount()->GetUsers().length(); x++) {
			Option(x + 1, app->GetCurrentAccount()->GetUsers()[x]->GetUsername());
		}
	}
	else {
		for (int x = 0; x < app->GetAccounts().length(); x++) {
			Option(x + 1, app->GetAccounts()[x]->GetEmail());
		}
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	if (app->IsAccountLoggedIn()) {
		if (index >= 0 && index < app->GetCurrentAccount()->GetUsers().length())
		{
			Line("Enter the password: ");
			std::string password = Utils::GetLineFromUser();
			if (app->GetCurrentAccount()->GetUsers()[index]->CheckPassword(password)) {
				app->LoginUser(app->GetCurrentAccount()->GetUsers()[index]);
				return true;
			}
		}
	}
	else {
		if (index >= 0 && index < app->GetAccounts().length())
		{
			Line("Enter the password: ");
			std::string password = Utils::GetLineFromUser();
			if (app->GetAccounts()[index]->CheckPassword(password)) {
				app->LoginAccount(app->GetAccounts()[index]);
				return true;
			}
		}
	}
	return false;
}

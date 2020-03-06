#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn()) {
		for (int x = 0; x < app->GetCurrentAccount()->GetUsers().length(); x++) {
			Option(x + 1, app->GetCurrentAccount()->GetUsers()[x]->GetUsername());
		}
		Option('G', "Guest");
	}
	else {
		Option(1, "Login");
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
				return app->LoginUser(app->GetCurrentAccount()->GetUsers()[index]);
			}
		}
		else if (choice == 'G') {
			return app->LoginUser(app->GetCurrentAccount()->dynamic_cast<User*>(GetGuest()));
		}
	}
	else {
		Line("Please enter your email: ");
		std::string email = Utils::GetLineFromUser();
		if (app->DoesEmailExist(email)) {
			Line("Enter the password: ");
			std::string password = Utils::GetLineFromUser();
			if (app->GetAccountFromEmail(email)->CheckPassword(password)) {
				app->LoginAccount(app->GetAccountFromEmail(email));
			}
		}
	}
	return false;
}

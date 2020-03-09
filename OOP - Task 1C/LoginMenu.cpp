#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn()) {
		for (int x = 1; x < app->GetCurrentAccount()->GetUsers().length(); x++)
			Option(x, app->GetCurrentAccount()->GetUsers()[x]->GetUsername());
		Option('G', app->GetCurrentAccount()->GetGuest()->GetUsername());
	}
	else {
		Option('L', "Login");
	}
}

bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '0';
	if (!app->IsAccountLoggedIn()) {
		if (choice == 'L') {
			std::string email = Question("Please enter your email");
			std::string password = Question("Enter the password");
			return app->LoginAccount(email, password);
		}
	}
	else {
		if (index >= 1 && index < app->GetCurrentAccount()->GetUsers().length())
		{
			std::string password = Question("Enter the password");
			if (app->GetCurrentAccount()->GetUsers()[index]->CheckPassword(password))
				return app->LoginUser(app->GetCurrentAccount()->GetUsers()[index]);
		}
		if (choice == 'G') {
			return app->LoginUser(app->GetCurrentAccount()->GetGuest());
		}
	}
	return false;
}

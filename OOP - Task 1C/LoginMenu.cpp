#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void LoginMenu::OutputOptions()
{
	if (app->IsAccountLoggedIn())
		for (int x = 0; x < app->GetCurrentAccount()->GetUsers().length(); x++)
			Option(x + 1, app->GetCurrentAccount()->GetUsers()[x]->GetUsername());
}

bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '1';
	if (!app->IsAccountLoggedIn()) {
		std::string email = Question("Please enter your email");
		std::string password = Question("Enter the password");
		return app->LoginAccount(email, password);
	}
	else {
		if (index >= 0 && index < app->GetCurrentAccount()->GetUsers().length())
		{
			std::string password = Question("Enter the password");
			if (app->GetCurrentAccount()->GetUsers()[index]->CheckPassword(password))
				return app->LoginUser(app->GetCurrentAccount()->GetUsers()[index]);
		}
	}
	return false;
}

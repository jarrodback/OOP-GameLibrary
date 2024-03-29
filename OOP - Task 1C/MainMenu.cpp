#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile of " + app->GetCurrentUser()->GetUsername());
		Option('L', "Logout of " + app->GetCurrentUser()->GetUsername());
	}
	else
	{
		if (app->IsAccountLoggedIn())
			Option('L', "User Login");
		else
			Option('L', "Account Login");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
	} break;
	case 'L':
	{
		if (app->IsAccountLoggedIn()) {
			if (app->IsUserLoggedIn()) {
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogoutUser();
				}
			}
			else
				LoginMenu("USER LOGIN", app);
		}
		else
		{
			// this would need to go to a LoginMenu - similar to StoreMenu
			// instead we just set logged in to true on the main app object
			std::string email = Question("Please enter your email");
			std::string password = Question("Enter the password");
			app->LoginAccount(email, password);
			if (app->IsAccountLoggedIn())
				LoginMenu("USER LOGIN", app);
		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			// this needs to go to a profile page - similar to StoreMenu
			// notice the if - this only works if somebody is logged in
			ProfileMenu(app->GetCurrentUser()->GetUsername() + "'s PROFILE", app);
		}
	} break;
	}

	return false;
}
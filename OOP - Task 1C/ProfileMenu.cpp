#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	//for (int x = 0; x < 5; x++)
	//{
	//	// adding 1 so the display is nicer for the user
	//	Option(i + 1, games[i]);
	//}

	//if (app->IsAccountLoggedIn())
	//{
	//	Option('L', "Woo");
	//}
	//else
	//{
	//	//Option('L', "Login");
	//}
}

bool ProfileMenu::HandleChoice(char choice)
{
	return false;
}

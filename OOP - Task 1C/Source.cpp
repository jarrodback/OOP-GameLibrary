#include "Application.h"
#include "MainMenu.h"

int main()
{
	Application app;
	std::string u = "alice@shu.com";
	std::string p = "password";
	app.LoginAccount(u, p);
	MainMenu("MAIN MENU", &app);
}





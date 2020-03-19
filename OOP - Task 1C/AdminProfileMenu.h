#pragma once
#include "Menu.h"
class AdminProfileMenu : public Menu
{
public:
	AdminProfileMenu(const std::string& title, Application* app);
	void OutputOptions() final;
	bool HandleChoice(char choice) final;
};


#pragma once

#include "Menu.h"
#include "SearchMenu.h"
#include "ListT.h"
#include <string>


class StoreMenu : public Menu
{
	public:
		StoreMenu(const std::string& title, Application * app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
};
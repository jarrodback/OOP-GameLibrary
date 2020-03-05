#pragma once

#include "Menu.h"
#include "SearchMenu.h"
#include "GamePurchaseMenu.h"
#include "ListT.h"
#include <string>
#include <iostream>
#include <cmath>


class StoreMenu : public Menu
{
	public:
		StoreMenu(const std::string& title, Application * app);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
};
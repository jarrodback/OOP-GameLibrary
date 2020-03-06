#pragma once
#include "Menu.h"

class GamePurchaseMenu : public Menu
{
	public:
		GamePurchaseMenu(const std::string& title, Application* app, const int& gameID);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:
		int gameID;
};



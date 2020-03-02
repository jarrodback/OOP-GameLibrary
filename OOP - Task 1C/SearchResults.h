#pragma once
#include "SearchMenu.h"
#include "Menu.h"

class SearchResults : public Menu
{
	public:
		SearchResults(const std::string& title, Application* app, List<Game*> filteredGames);
		void OutputOptions() final;
		bool HandleChoice(char choice) final;
	private:
		List<Game*> filteredGames;
};


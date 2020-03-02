#pragma once
#include "Menu.h"
#include "SearchResults.h"

class SearchMenu : public Menu
{
	public:
   	  SearchMenu(const std::string& title, Application* app);
	  void OutputOptions() final;
	  bool HandleChoice(char choice) final;
	private:
	  List<Game*> filteredGames;
};
#include "SearchResults.h"

SearchResults::SearchResults(const std::string& title, Application* app, List<Game*> filteredGames) : Menu(title, app), filteredGames(filteredGames)
{
	Paint();
}

void SearchResults::OutputOptions()
{
	for (int i = 0; i < filteredGames.length(); i++)
	{
		// adding 1 so the display is nicer for the user
		Option(i + 1, filteredGames[i]->GetName());
	}
	Line();
}

bool SearchResults::HandleChoice(char choice)
{
	return false;
}

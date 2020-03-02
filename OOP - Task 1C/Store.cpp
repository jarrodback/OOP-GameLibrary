#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		delete games[i];
	}
}

const List<Game*> Store::GetGames() const
{
	return games;
}

void Store::AddToGames(Game* game)
{
	games.addAtEnd(game);
}

void Store::RemoveFromGames(Game* game)
{
	games.deleteOne(game);
}

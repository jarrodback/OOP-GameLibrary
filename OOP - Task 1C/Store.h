#pragma once

#include "Game.h"
#include "ListT.h"
class Store
{
	public:
		Store();
		~Store();
		const List<Game*> GetGames() const;
		void AddToGames(Game*);
		void RemoveFromGames(Game*);
	private:
		List<Game*> games;

};
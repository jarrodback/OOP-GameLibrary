#pragma once

#include "Game.h"
#include "ListT.h"
class Store
{
	public:
		Store();
		~Store();
		List<Game*> games;
		//Game* games[9] = { }; // TODO: should be a dynamic collection
	private:
};
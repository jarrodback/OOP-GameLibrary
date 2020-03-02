#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*);
		~LibraryItem();
		const std::string& GetName() const;
		const Date GetDate() const;
	private:
		const Game *game;
		const Date purchased;
};
bool operator<(LibraryItem a, LibraryItem b);
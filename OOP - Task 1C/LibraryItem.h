#pragma once

#include "Game.h"
#include "Date.h"
#include <ostream>

class LibraryItem
{
	public:
		LibraryItem(const Date&, Game*);
		~LibraryItem();
		const std::string& GetName() const;
		int GetGameID() const;
		std::ostream& Write(std::ostream& os) const;
		Date GetDate() const;
	private:
		const Game *game;
		const Date purchased;
};
std::ostream& operator<<(std::ostream& os, LibraryItem const& li);
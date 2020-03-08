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
		const int& getMinutesPlayed();
		void addMinutesPlayed(int amt);
		const Date GetDate() const;
		const Game GetGame() const;
	private:
		const Game *game;
		const Date purchased;
		int timePlayed;		
};
std::ostream& operator<<(std::ostream& os, LibraryItem const& li);
bool operator<(LibraryItem a, LibraryItem b);

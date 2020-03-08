#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: purchased(date), game(game), timePlayed(0)
{
}

LibraryItem::~LibraryItem()
{
}

const std::string& LibraryItem::GetName() const
{
	return game->GetName();
}

std::ostream& LibraryItem::Write(std::ostream& os) const {
	os << "LIBRARY-ITEM" << "\n";
	os << game->GetID() << "\n";
	os << purchased << "\n";
	//GET GAME TIME 
	os << timePlayed << "\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, LibraryItem const& li)
{
	return li.Write(os);
}

const int& LibraryItem::getMinutesPlayed()
{
	return timePlayed;
}

void LibraryItem::addMinutesPlayed(int amt)
{
	timePlayed += amt;
}
const Date LibraryItem::GetDate() const
{
	return purchased;
}

const Game LibraryItem::GetGame() const
{
	return *game;
}


bool operator<(LibraryItem a, LibraryItem b)
{
	return (a.GetName() < b.GetName());
}

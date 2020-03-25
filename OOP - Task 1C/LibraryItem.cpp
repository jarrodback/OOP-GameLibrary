#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game, int timePlayed)
	: purchased(date), game(game), timePlayed(timePlayed)
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
	os << timePlayed << "\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, LibraryItem const& li)
{
	return li.Write(os);
}

const int& LibraryItem::getMinutesPlayed() const
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

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


bool operator<(LibraryItem a, LibraryItem b)
{
	return (a.GetName() > b.GetName());
}

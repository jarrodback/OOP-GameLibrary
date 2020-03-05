#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: purchased(date), game(game), minutesplayed(0)
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
	return minutesplayed;
}

void LibraryItem::addMinutesPlayed(int amt)
{
	minutesplayed += amt;
}

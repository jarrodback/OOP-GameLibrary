#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, Game* game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

const std::string& LibraryItem::GetName() const
{
	return game->GetName();
}

bool operator<(LibraryItem a, LibraryItem b)
{
	return (a.GetName() > b.GetName());
}

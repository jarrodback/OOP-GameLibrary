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

int LibraryItem::GetGameID() const
{
	return game->GetID();
}

std::ostream& LibraryItem::Write(std::ostream& os) const {

}

std::ostream& operator<<(std::ostream& os, LibraryItem const& li)
{
	os << "LIBRARY-ITEM";
	os << li.GetGameID();
	//GET DATE
	//NEED TO ADD A GAMETIME
	return os;
}
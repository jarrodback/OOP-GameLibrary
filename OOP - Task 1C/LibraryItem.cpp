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

std::ostream& LibraryItem::Write(std::ostream& os) const {
	os << "LIBRARY-ITEM";
	os << game->GetID();
	os << purchased;
	//GET GAME TIME 
	return os;
}

std::ostream& operator<<(std::ostream& os, LibraryItem const& li)
{
	return li.Write(os);
}
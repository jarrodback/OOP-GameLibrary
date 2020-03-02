#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created)
	: User(username, password, created)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

const List<LibraryItem*> Player::GetLibrary() const
{
	return library;
}

void Player::AddToLibrary(LibraryItem* libraryItem)
{
	library.addAtEnd(libraryItem);
}

void Player::RemoveFromLibrary(LibraryItem* libraryItem)
{
	library.deleteOne(libraryItem);
}

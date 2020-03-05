#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const int& credits)
	: User(username, password, created){
	this->credits = credits;
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

const int Player::getCredits()
{
	return credits;
}

void Player::AddToLibrary(LibraryItem* libraryItem)
{
	library.addAtEnd(libraryItem);
}

void Player::RemoveFromLibrary(LibraryItem* libraryItem)
{
	library.deleteOne(libraryItem);
}

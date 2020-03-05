#include "Player.h"
#include "Admin.h"

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

std::ostream& Player::Write(std::ostream& os){

	Admin* ptr = dynamic_cast<Admin*>(this);
	if (ptr)
	{
		os << "ACCOUNT-ADMIN" << "\n";
		os << created << "\n";
		os << username << "\n";
		os << password << "\n";
		//Credits
		for (int x = 0; x < library.length(); x++)
		{
			os << *library[x];
		}
		return os;
	}
	else {
		os << "ACCOUNT-PLAYER" << "\n";
		os << created << "\n";
		os << username << "\n";
		os << password << "\n";
		//Credits
		for (int x = 0; x < library.length(); x++)
		{
			os << *library[x];
		}
		return os;
	}
}

std::ostream& operator<<(std::ostream& os, Player& p)
{
	return p.Write(os);
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

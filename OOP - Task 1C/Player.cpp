#include "Player.h"
#include "Admin.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const float& credits)
	: User(username, password, created){
	this->credits = credits;
}

Player::~Player()
{
	for (int i = 0; i < library.size(); ++i)
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
		os << credits << "\n";
		//Credits
		for (int x = 0; x < library.size(); x++)
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
		os << credits << "\n";
		//Credits
		for (int x = 0; x < library.size(); x++)
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

std::vector<LibraryItem*> Player::GetLibrary() const
{
	return library;
}
bool Player::DoesLibraryContain(LibraryItem* libraryItem) const {
	for (int x = 0; x < library.size(); x++)
		if (library.at(x) == libraryItem)
			return true;
	return false;
}

const float Player::getCredits() const
{
	return credits;
}

void Player::deductCredits(float amt)
{
	this->credits -= amt;
}

void Player::addCredits(float amt)
{
	this->credits += amt;
}


void Player::AddToLibrary(LibraryItem* libraryItem)
{
	library.push_back(libraryItem);
}

void Player::RemoveFromLibrary(LibraryItem* libraryItem)
{
	int index = -1;
	for (int x = 0; x < library.size(); x++) {
		if (library[x] == libraryItem)
			index = x;
	}
	library.erase(library.begin() + index, library.begin() + index+1);
}

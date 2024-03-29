#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
	users.addInFront(new Guest);
}

Account::~Account()
{
	for (int i = 0; i < users.length(); ++i)
	{
		delete users[i];
	}
}

const List<User*> Account::GetUsers() const
{
	return users;
}

void Account::AddToUsers(User* user)
{
	users.addAtEnd(user);
}

void Account::RemoveFromUsers(User* user)
{
	users.deleteOne(user);
}

std::string Account::GetEmail()
{
	return email;
}

const bool Account::CheckPassword(std::string& password) const
{
	return password == this->password;
}

Guest* Account::GetGuest() const
{
	return dynamic_cast<Guest*>(users[0]);
}
std::ostream& Account::write(std::ostream& os) const {
	os << "ACCOUNT" << "\n";
	os << created << "\n";
	os << email << "\n";
	os << password << "\n";

	for (int i = 0; i < users.length(); i++)
	{
		os << *users[i];
	}

	return os;
}

std::ostream& operator<<(std::ostream& os, Account const& a)
{
	return a.write(os);
}

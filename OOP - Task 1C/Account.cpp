#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const Date& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}

std::string Account::getEmail()
{
	return email;
}

const bool Account::CheckPassword(std::string& password) const
{
	return password == this->password;
}

std::ostream& Account::write(std::ostream& os) const {
	os << "ACCOUNT";
	os << created;
	os << email;
	os << password;
	return os;
}

std::ostream& operator<<(std::ostream& os, Account const& a)
{
	return a.write(os);
}
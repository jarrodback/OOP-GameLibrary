#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created)
	: Player(username, password, created)
{
}

Admin::~Admin()
{
}

std::ostream& Admin::Write(std::ostream& os) const {
	os << "ACCOUNT-PLAYER" << "\n";
	os << created << "\n";
	os << username << "\n";
	os << password << "\n";
	//Credits
	for (int x = 0; x < library.length(); x++)
	{
		os << *library[x] << "\n";
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, Admin const& p)
{
	return p.Write(os);
}

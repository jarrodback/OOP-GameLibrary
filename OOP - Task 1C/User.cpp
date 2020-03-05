#include "User.h"
#include "Player.h"
#include "Admin.h"

User::User(const std::string& username, const std::string& password, const Date& created)
	: username(username), password(password), created(created)
{
}

User::~User()
{
}

const std::string& User::GetUsername() const
{
	return username;
}

const bool User::CheckPassword(std::string& password) const
{
	return password == this->password;
}

std::ostream& User::Write(std::ostream& os){
	Player* ptr = dynamic_cast<Player*>(this);
	if (ptr) {
		return ptr->Write(os);
	}
	else
	{
		return os;
	}
}

std::ostream& operator<<(std::ostream& os, User& p)
{
	return p.Write(os);
}
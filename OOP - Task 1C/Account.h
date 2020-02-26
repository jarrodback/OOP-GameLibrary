#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		List<User*> users;
		//User* users[3] = { }; // TODO: replace with custom List<T> class
	private:
		std::string email;
		std::string password;
		Date created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};
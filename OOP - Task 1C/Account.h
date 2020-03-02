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
		std::string getEmail();
		const bool CheckPassword(std::string&) const;
	private:
		std::string email;
		std::string password;
		Date created; 
};
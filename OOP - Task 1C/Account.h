#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"
#include <ostream>

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		List<User*> users;
		std::string getEmail();
		const bool CheckPassword(std::string&) const;
		std::ostream& write(std::ostream& os) const;
	private:
		std::string email;
		std::string password;
		Date created; 
};

std::ostream& operator<<(std::ostream& os, Account const& a);
#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"
#include "Guest.h"
#include <ostream>

class Account
{
	public:
		Account(const std::string&, const std::string&, const Date&);
		~Account();
		const List<User*> GetUsers() const;
		void AddToUsers(User*);
		void RemoveFromUsers(User*);
		std::string GetEmail();
		const bool CheckPassword(std::string&) const;
		Guest* GetGuest() const;
		std::ostream& write(std::ostream& os) const;
	private:
		std::string email;
		std::string password;
		Date created; 
		List<User*> users;
		Guest* guest;
};
};

std::ostream& operator<<(std::ostream& os, Account const& a);


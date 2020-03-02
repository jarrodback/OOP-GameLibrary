#pragma once

#include <string>
#include "Player.h"
#include "ListT.h"

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
	private:
		std::string email;
		std::string password;
		Date created; 
		List<User*> users;

};
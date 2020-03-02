#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date&);
		virtual ~User();
		const std::string& GetUsername() const;
		const bool CheckPassword(std::string&) const;

	private:
		std::string username;
		std::string password;
		Date created;  
};
#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string&, const std::string&, const Date&);
		User(const std::string&);
		virtual ~User();
		const std::string& GetUsername() const;
		const bool CheckPassword(std::string&) const;

		std::ostream& Write(std::ostream& os);

	private:
	
	protected:
		Date created;  
		std::string username;
		std::string password;
};

std::ostream& operator<<(std::ostream& os, User& p);
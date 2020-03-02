#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		List<LibraryItem*> library;
	private:
};

std::ostream& operator<<(std::ostream& os, Player const& p);
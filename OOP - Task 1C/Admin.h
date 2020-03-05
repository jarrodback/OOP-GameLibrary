#pragma once

#include <string>
#include "Player.h"

class Admin : public Player
{
	public:
		Admin(const std::string&, const std::string&, const Date&);
		~Admin();
		std::ostream& Write(std::ostream& os) const;
};

std::ostream& operator<<(std::ostream& os, Admin const& p);
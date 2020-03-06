#pragma once

#include <string>
#include <ostream>

class Game
{
	public:
		Game(const std::string&, const std::string&, int, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		int GetCost() const;
		int GetID() const;
		std::ostream& Write(std::ostream& os) const;
	private:
		std::string name;
		std::string description;
		int cost;
		int ageRating;
		int gameID;
};

std::ostream& operator<<(std::ostream& os, Game const& game);

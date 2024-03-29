#pragma once

#include <string>
#include <ostream>

class Game
{
	public:
		Game(const std::string&, const std::string&, float, int, int);
		~Game();

		const std::string& GetName() const;
		const std::string& GetDescription() const;
		float GetCost() const;
		void addLike();
		void addDislike();
		float calculateRating();
		int GetID() const;
		std::ostream& Write(std::ostream& os) const;
		std::istream& Load(std::istream& is);
	private:
		std::string name;
		std::string description;
		float cost;
		int ageRating;
		float likes;
		float dislikes;
		int gameID;
};

std::ostream& operator<<(std::ostream& os, Game const& game);

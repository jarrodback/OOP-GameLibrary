#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating, int ID)
	: name(name), description(desc), cost(cost), ageRating(rating), gameID(ID)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}


std::ostream& Game::Write(std::ostream& os) const
{
	os << "GAME";
	os << gameID;
	os << name;
	os << description;
	os << cost;
	os << ageRating;
	return os;
}

std::ostream& operator<<(std::ostream& os, Game const& game)
{
	return game.Write(os);
}
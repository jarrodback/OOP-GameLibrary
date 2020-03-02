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

int Game::GetAge() const
{
	return ageRating;
}

int Game::GetID() const
{
	return gameID;
}

std::ostream& operator<<(std::ostream& os, Game const& game)
{
	os << "GAME";
	os << game.GetID();
	os << game.GetName();
	os << game.GetDescription();
	os << game.GetCost();
	os << game.GetAge();
	return os;
}
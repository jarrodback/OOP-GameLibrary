#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating)
	: name(name), description(desc), cost(cost), ageRating(rating), likes(0.0), dislikes(0.0)
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

void Game::addLike()
{
	++likes;
}

void Game::addDislike()
{
	++dislikes;
}

float Game::calculateRating()
{
	if (likes == 0 && dislikes == 0)
		return round(0.0);
	int total = likes + dislikes;
	return (likes / total) * 100;
}

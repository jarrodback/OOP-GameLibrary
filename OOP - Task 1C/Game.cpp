#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating, int ID)
	: name(name), description(desc), cost(cost), ageRating(rating), gameID(ID), likes(0.0), dislikes(0.0)
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
int Game::GetID() const
{
	return this->gameID;
}


std::ostream& Game::Write(std::ostream& os) const
{
	os << "GAME" << "\n";
	os << gameID << "\n";
	os << name << "\n";
	os << description << "\n";
	os << cost << "\n";
	os << ageRating << "\n";
	return os;
}

std::ostream& operator<<(std::ostream& os, Game const& game)
{
	return game.Write(os);
}

#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created)
	: User(username, password, created)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

int Player::getCredits()
{
	return credits;
}

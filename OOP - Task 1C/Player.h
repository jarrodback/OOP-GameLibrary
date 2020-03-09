#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include <vector>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, const float& credits);
		~Player();
		std::ostream& Write(std::ostream& os);
		std::vector<LibraryItem*> GetLibrary() const;
		const float getCredits();
		void deductCredits(float amt);
		void addCredits(float amt);
		void AddToLibrary(LibraryItem*);
		void RemoveFromLibrary(LibraryItem*);		
	private:
		
	protected:
		std::vector<LibraryItem*> library;
		float credits;
};
std::ostream& operator<<(std::ostream& os, Player& p);

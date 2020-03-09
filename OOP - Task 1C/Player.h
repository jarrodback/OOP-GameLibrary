#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include <vector>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, const int& credits);
		~Player();
		std::ostream& Write(std::ostream& os);
		std::vector<LibraryItem*> GetLibrary() const;
		const int getCredits();
		void deductCredits(int amt);
		void addCredits(int amt);
		void AddToLibrary(LibraryItem*);
		void RemoveFromLibrary(LibraryItem*);		
	private:
		
	protected:
		std::vector<LibraryItem*> library;
		int credits;
};
std::ostream& operator<<(std::ostream& os, Player& p);

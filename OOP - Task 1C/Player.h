#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, const int& credits);
		~Player();
		const List<LibraryItem*> GetLibrary() const;
		const int getCredits();
		void deductCredits(int amt);
		void addCredits(int amt);
		void AddToLibrary(LibraryItem*);
		void RemoveFromLibrary(LibraryItem*);		
	private:
		List<LibraryItem*> library;
		int credits;
};
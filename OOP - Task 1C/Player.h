#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include <vector>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		std::vector<LibraryItem*> GetLibrary() const;
		void AddToLibrary(LibraryItem*);
		void RemoveFromLibrary(LibraryItem*);
	private:
		std::vector<LibraryItem*> library;
};
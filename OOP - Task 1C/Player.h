#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&);
		~Player();
		std::ostream& Write(std::ostream& os);

		const List<LibraryItem*> GetLibrary() const;
		void AddToLibrary(LibraryItem*);
		void RemoveFromLibrary(LibraryItem*);
	private:
		
	protected:
		List<LibraryItem*> library;
};

std::ostream& operator<<(std::ostream& os, Player& p);

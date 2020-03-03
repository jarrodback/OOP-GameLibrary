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
		std::ostream& Write(std::ostream& os) const;
		const List<LibraryItem*> GetLibrary() const;
		void AddToLibrary(LibraryItem*);
		void RemoveFromLibrary(LibraryItem*);
	private:
		List<LibraryItem*> library;

};

std::ostream& operator<<(std::ostream& os, Player const& p);

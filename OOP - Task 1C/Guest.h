#pragma once
#include "User.h"
#include <vector>
#include "LibraryItem.h"
class Guest : public User
{
public:
	Guest();
	~Guest();
	std::vector<LibraryItem*> GetLibrary() const;
	void AddToLibrary(LibraryItem*);
	void RemoveFromLibrary(LibraryItem*);
	std::ostream& Write(std::ostream& os);
private:
	std::vector<LibraryItem*> library;
};
std::ostream& operator<<(std::ostream& os, Guest& p);

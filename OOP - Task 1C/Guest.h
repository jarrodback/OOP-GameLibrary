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
private:
	std::vector<LibraryItem*> library;
};


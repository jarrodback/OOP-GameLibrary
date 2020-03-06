#pragma once
#include "User.h"
#include <vector>
#include "LibraryItem.h"
class Guest : public User
{
public:
	Guest(const std::string&, const std::string&, const Date&, const int& credits);
	~Guest();
	std::vector<LibraryItem*> GetLibrary() const;
	void AddToLibrary(LibraryItem*);
	void RemoveFromLibrary(LibraryItem*);
private:
	std::vector<LibraryItem*> library;
};


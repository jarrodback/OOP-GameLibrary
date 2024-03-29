#include "Guest.h"

Guest::Guest()	: User("Guest") {
}

Guest::~Guest()
{
}

std::vector<LibraryItem*> Guest::GetLibrary() const
{
	return library;
}

void Guest::AddToLibrary(LibraryItem* libraryItem)
{
	library.push_back(libraryItem);
}

void Guest::RemoveFromLibrary(LibraryItem* libraryItem)
{
	int index = -1;
	for (int x = 0; x < library.size(); x++) {
		if (library[x] == libraryItem)
			index = x;
	}
	library.erase(library.begin() + index, library.begin() + index + 1);
}

std::ostream& Guest::Write(std::ostream& os)
{
	// TODO: insert return statement here
	os << "GUEST" << "\n";
	for (int x = 0; x < library.size(); x++)
	{
		os << *library[x];
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, Guest& p)
{
	// TODO: insert return statement here
	return p.Write(os);
}

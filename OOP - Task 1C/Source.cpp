//#include "MainMenu.h"
#include "Application.h"
#include "MainMenu.h"
#include "Account.h"
#include "Admin.h"

// TODO: Remove from global scope once menu system is integrated
Application app;
void createHardcodedTestData()
{
	Date testDate(10, 10, 1999);
	// Setup store with some games
	app.GetStore().games.addAtEnd(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().games.addAtEnd(new Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().games.addAtEnd(new Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().games.addAtEnd(new Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().games.addAtEnd(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().games.addAtEnd(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().games.addAtEnd(new Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().games.addAtEnd(new Game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	app.GetStore().games.addAtEnd(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	//// Create some users
	Player* u1 = new Admin("Alice", "password", testDate);
	Player* u2 = new Player("Bob", "password", testDate);
	Player* u3 = new Player("Charlie", "password", testDate);

	//// With some games in their library
	u1->library.addAtEnd(new LibraryItem(testDate, app.GetStore().games[7]));
	u1->library.addAtEnd(new LibraryItem(testDate, app.GetStore().games[1]));
	u2->library.addAtEnd(new LibraryItem(testDate, app.GetStore().games[2]));
	u2->library.addAtEnd(new LibraryItem(testDate, app.GetStore().games[3]));
	u3->library.addAtEnd(new LibraryItem(testDate, app.GetStore().games[3]));
	u3->library.addAtEnd(new LibraryItem(testDate, app.GetStore().games[6]));

	//// Make an account and attach the users
	app.accounts.addAtEnd(new Account("alice@shu.com", "password", testDate));
	app.accounts[0]->users.addAtEnd(u1);
	app.accounts[0]->users.addAtEnd(u2);
	app.accounts[0]->users.addAtEnd(u3);

	//// TODO: We need a login menu for accounts, for now we log in the only account
	app.LoginAccount("alice@shu.ac.uk", "password");
}

int main()
{
	createHardcodedTestData();
	MainMenu("MAIN MENU", &app);
}





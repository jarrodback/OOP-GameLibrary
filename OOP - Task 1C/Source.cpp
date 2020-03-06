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
	app.GetStore().games.addAtEnd(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5, 0));
	app.GetStore().games.addAtEnd(new Game("Braid", "A time twisting puzzle game.", 499, 15, 1));
	app.GetStore().games.addAtEnd(new Game("Factorio", "Build a complicated factory in space.", 1599, 12, 2));
	app.GetStore().games.addAtEnd(new Game("LIMBO", "Watch out for that spider.", 299, 12, 3));
	app.GetStore().games.addAtEnd(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15, 4));
	app.GetStore().games.addAtEnd(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15, 5));
	app.GetStore().games.addAtEnd(new Game("Half Life 3", "It's never coming out.", 5999, 18, 6));
	app.GetStore().games.addAtEnd(new Game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18, 7));
	app.GetStore().games.addAtEnd(new Game("Brothers", "Split your brain into two thumbs.", 799, 15, 8));

	//// Create some users
	Player* u1 = new Admin("Alice", "password", testDate);
	Player* u2 = new Player("Bob", "password", testDate);
	Player* u3 = new Player("Charlie", "password", testDate);

	//// With some games in their library
	u1->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[7]));
	u1->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[1]));
	u2->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[2]));
	u2->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[3]));
	u3->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[3]));
	u3->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[6]));

	//// Make an account and attach the users
	app.AddToAccounts(new Account("alice@shu.com", "password", testDate));
	app.GetAccounts()[0]->AddToUsers(u1);
	app.GetAccounts()[0]->AddToUsers(u2);
	app.GetAccounts()[0]->AddToUsers(u3);


	//// TODO: We need a login menu for accounts, for now we log in the only account
	//app.LoginAccount("alice@shu.ac.uk", "password");
}

int main()
{
	app.Load();
	createHardcodedTestData();
	MainMenu("MAIN MENU", &app);
	app.Save();
}





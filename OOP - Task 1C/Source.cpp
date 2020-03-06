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
	Date testDate2(10, 10, 2020);

	// Setup store with some games
	app.GetStore().AddToGames(new Game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	app.GetStore().AddToGames(new Game("Braid", "A time twisting puzzle game.", 499, 15));
	app.GetStore().AddToGames(new Game("Factorio", "Build a complicated factory in space.", 1599, 12));
	app.GetStore().AddToGames(new Game("LIMBO", "Watch out for that spider.", 299, 12));
	app.GetStore().AddToGames(new Game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	app.GetStore().AddToGames(new Game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	app.GetStore().AddToGames(new Game("Half Life 3", "It's never coming out.", 5999, 18));
	app.GetStore().AddToGames(new Game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	app.GetStore().AddToGames(new Game("Brothers", "Split your brain into two thumbs.", 799, 15));

	//// Create some users
	Player* u1 = new Admin("Alice", "password", testDate, 200);
	Player* u2 = new Player("Bob", "password", testDate, 1000);
	Player* u3 = new Player("Charlie", "password", testDate, 500);

	//// With some games in their library
	u1->AddToLibrary(new LibraryItem(testDate2, app.GetStore().GetGames()[7]));
	u1->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[1]));
	u2->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[2]));
	u2->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[3]));
	u3->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[3]));
	u3->AddToLibrary(new LibraryItem(testDate, app.GetStore().GetGames()[6]));
	u3->RemoveFromLibrary(u3->GetLibrary()[1]);

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
	createHardcodedTestData();
	MainMenu("MAIN MENU", &app);
}





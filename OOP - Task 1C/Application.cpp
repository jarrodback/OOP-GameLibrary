#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
	Load();
}

Application::~Application()
{
	Save();
	for (int i = 0; i < accounts.length(); i++)
	{
		delete accounts[i];
	}
}

bool Application::IsUserLoggedIn() const
{
	return currentUser != nullptr;
}

bool Application::IsUserAdmin() const
{
	Admin* ptr = dynamic_cast<Admin*>(currentUser);
	if (ptr) {
		return true;
	}
	return false;
}

bool Application::IsUserGuest() const
{
	Guest* ptr = dynamic_cast<Guest*>(currentUser);
	if (ptr) {
		return true;
	}
	return false;
}

bool Application::IsAccountLoggedIn() const
{
	return currentAccount != nullptr;
}

Account* Application::GetCurrentAccount() const
{
	return currentAccount;
}

User* Application::GetCurrentUser() const
{
	return currentUser;
}

Account* Application::GetAccountFromEmail(std::string& email) const
{
	for (int x = 0; x < accounts.length(); x++)
		if (accounts[x]->GetEmail() == email)
			return accounts[x];
	return 0;
}

bool Application::DoesEmailExist(std::string& email) const
{
	for (int x = 0; x < accounts.length(); x++)
		if (accounts[x]->GetEmail() == email)
			return true;
	return false;
}

Store& Application::GetStore()
{
	return store;
}

bool Application::LoginAccount(std::string& email, std::string& password)
{
	for (int x = 0; x < accounts.length(); x++)
		if (accounts[x]->GetEmail() == email){
			if (accounts[x]->CheckPassword(password)) {
				currentAccount = accounts[x];
				return true;
			}
		}
	return false;
}

bool Application::LoginUser(User* const user)
{
	currentUser = user;
	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Application::Save()
{
	std::ofstream fout;
	fout.open("data.txt");
	if (fout.fail()) std::cout << "\nError saving data.";
	else
	{
		for (int i = 0; i < store.GetGames().length(); i++)
			fout << *store.GetGames()[i];

		for (int i = 0; i < accounts.length(); i++)
			fout << *accounts[i];

		fout << "END OF FILE";
	}
	fout.close();
}

void Application::Load()
{
	std::ifstream fin;
	fin.open("data.txt");
	if (fin.fail()) std::cout << "\nError loading game.";
	else
	{
		std::string nextLine = "";
		std::getline(fin, nextLine);
		while (nextLine == "GAME") {

			int count = 0;
			int cost, age, gameID, like, dislike;
			std::string name, desc;

			while (std::getline(fin, nextLine) && nextLine != "GAME" && nextLine != "ACCOUNT")
			{
				std::stringstream linestream(nextLine);

				switch (count) {
				case 0:
					gameID = std::stoi(nextLine);
					break;
				case 1:
					name = nextLine;
					break;
				case 2:
					desc = nextLine;
					break;
				case 3:
					cost = std::stoi(nextLine);
					break;
				case 4:
					age = std::stoi(nextLine);
					break;
				case 5:
					like = std::stoi(nextLine);
					break;
				case 6:
					dislike = std::stoi(nextLine);
					break;
				}
				count++;
			}
			GetStore().AddToGames(new Game(name, desc, cost, age, gameID));
			for (int i = 0; i < GetStore().GetGames().length(); i++)
			{
				if (GetStore().GetGames()[i]->GetName() == name)
				{
					for (int x = 0; x < like; x++)
					{
						GetStore().GetGames()[i]->addLike();
					}
					for (int x = 0; x < dislike; x++)
					{
						GetStore().GetGames()[i]->addDislike();
					}
				}
			}
		}
		int accountCount = -1;
		while (nextLine == "ACCOUNT") {
			accountCount++;
			//Create Account
			Date dateCreated;
			std::string email, password;
			fin >> dateCreated >> email >> password;
			accounts.addInFront(new Account(email,password,dateCreated));

			fin >> nextLine;
			while (nextLine == "ACCOUNT-PLAYER" || nextLine == "ACCOUNT-ADMIN" || nextLine == "GUEST")
			{
				std::string accountType = nextLine;
				Date dateCreated;
				std::string username, password;
				int credits;

				if (accountType == "ACCOUNT-PLAYER" || nextLine == "ACCOUNT-ADMIN")
				{
					fin >> dateCreated >> username >> password >> credits;
					if (accountType == "ACCOUNT-PLAYER")
					{
						accounts[accountCount]->AddToUsers(new Player(username, password, dateCreated, credits));
					}
					else if (accountType == "ACCOUNT-ADMIN")
					{
						accounts[accountCount]->AddToUsers(new Admin(username, password, dateCreated, credits));
					}
				}
				//else if (accountType == "GUEST")
				//{
				//	accounts[accountCount]->AddToUsers(new Guest());
				//}
				fin >> nextLine;
				//CHECK IF NEXT LINE IS LIBRARY ITEM OR ANOTHER USER
				while (nextLine == "LIBRARY-ITEM") {
					//Create LibraryItem
					int gameID, timePlayed;
					Date dateCreated;
					fin >> gameID >> dateCreated >> timePlayed;

					if (accountType != "GUEST")
					{
						for (int i = 0; i < accounts[accountCount]->GetUsers().length(); i++)
							if (accounts[accountCount]->GetUsers()[i]->GetUsername() == username)
							{
								Player* player = dynamic_cast<Player*>(accounts[accountCount]->GetUsers()[i]);
								for (int x = 0; x < GetStore().GetGames().length(); x++)
									if (GetStore().GetGames()[x]->GetID() == gameID)
									{
										player->AddToLibrary(new LibraryItem(dateCreated, GetStore().GetGames()[x], timePlayed));
									}
							}
					}
					else
					{
						Guest* guest = dynamic_cast<Guest*>(accounts[accountCount]->GetGuest());
						for (int x = 0; x < GetStore().GetGames().length(); x++)
							if (GetStore().GetGames()[x]->GetID() == gameID)
							{
								guest->AddToLibrary(new LibraryItem(dateCreated, GetStore().GetGames()[x], timePlayed));
							}
					}
					fin >> nextLine;
				}
			}
		}
	}
	fin.close();
}

const List<Account*> Application::GetAccounts() const
{
	return accounts;
}

void Application::AddToAccounts(Account* const account)
{
	accounts.addAtEnd(account);
}

void Application::RemoveFromAccounts(Account* const account)
{
	accounts.deleteOne(account);
}

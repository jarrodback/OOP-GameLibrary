#include "Application.h"

Application::Application() : currentAccount(nullptr), currentUser(nullptr)
{
}

Application::~Application()
{
	for (int i = 0; i < 1; ++i)
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

bool Application::LoginAccount(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = accounts[0];

	return true;
}
bool Application::LoginAccount(Account* const account)
{
	// TODO: This currently always logs you in as the first account
	currentAccount = account;
	return true;
}

bool Application::LoginUser(const std::string& username, const std::string& password)
{
	// TODO: This currently always logs you in as the first user
	currentUser = currentAccount->GetUsers()[0];
	return true;
}

bool Application::LoginUser(User* const user)
{
	// TODO: This currently always logs you in as the first user
	currentUser = user;
	return true;
}

void Application::LogoutUser()
{
	currentUser = nullptr;
}

void Save(Game& game)
{
	std::ofstream fout;
	fout.open("data.txt");
	if (fout.fail()) std::cout << "\nError saving game.";
	else fout << game; // operator << for Game instances
	fout.close();
}

void Load(Game& game)
{
	std::ifstream fin;
	fin.open("data.txt");
	if (fin.fail()) std::cout << "\nError loading game.";
	//else fin >> game;   // operator >> for Game instances
	fin.close();
}

const List<Account*> Application::GetAccounts() const
{
	return accounts;
}

void Application::AddToAccounts(Account* account)
{
	accounts.addAtEnd(account);
}

void Application::RemoveFromAccounts(Account* account)
{
	accounts.deleteOne(account);
}

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

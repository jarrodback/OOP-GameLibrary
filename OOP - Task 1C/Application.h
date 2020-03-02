#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"
#include "Admin.h"

class Application
{
public:
	Application();
	~Application();

	bool IsAccountLoggedIn() const;
	bool IsUserLoggedIn() const;
	bool IsUserAdmin() const;
	Account* GetCurrentAccount() const;
	User* GetCurrentUser() const;

	Store& GetStore();

	bool LoginAccount(const std::string& email, const std::string& password);
	bool LoginAccount(Account* const account);
	bool LoginUser(const std::string& username, const std::string& password);
	bool LoginUser(User* const user);
	void LogoutUser();

	const List<Account*> GetAccounts() const;
	void AddToAccounts(Account*);
	void RemoveFromAccounts(Account*);
private:
	List<Account*> accounts;
	Store store;
	Account* currentAccount;
	User* currentUser;
};
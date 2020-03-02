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
	List<Account*> accounts;

	void Save();
	void Load();
private:
	Store store;
	Account* currentAccount;
	User* currentUser;
};
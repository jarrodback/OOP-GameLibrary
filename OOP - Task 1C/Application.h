#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"
#include "Admin.h"
#include <fstream>
#include <sstream>
#include <iostream>

class Application
{
public:
	Application();
	~Application();

	bool IsAccountLoggedIn() const;
	bool IsUserLoggedIn() const;
	bool IsUserAdmin() const;
	bool IsUserGuest() const;
	Account* GetCurrentAccount() const;
	User* GetCurrentUser() const;
	Account* GetAccountFromEmail(std::string&) const;
	bool DoesEmailExist(std::string&) const;
	Store& GetStore();
	bool LoginAccount(std::string& username, std::string& password);
	bool LoginUser(User* const user);
	void LogoutUser();
	std::ostream& Write(std::ostream& os) const;
	const List<Account*> GetAccounts() const;
	void AddToAccounts(Account* const);
	void RemoveFromAccounts(Account* const);
private:
	void Load();
	void Save();
	List<Account*> accounts;
	Store store;
	Account* currentAccount;
	User* currentUser;
};
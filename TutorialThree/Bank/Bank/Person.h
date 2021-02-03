#pragma once
#include "CurrentAccount.h"
#include "Account.h"
#include "Date.h"

#include <string>
#include <vector>


class Person {
public:
	Person(std::string);
	//Setters
	bool addCurrentAccount(int, double);
	bool closeAccount(int);
	bool creditMoney(int, double);
	bool debitMoney(int, double);
	//Getters
	void printAllAccounts();
	std::string getName() const;
	virtual ~Person();
private:
	const std::string name;
	const Date dob;
	std::vector<Account*> accounts;
};
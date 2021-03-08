#pragma once
#include "CurrentAccount.h"
#include "SavingsAccount.h"
#include "Account.h"
#include "Date.h"

#include <string>
#include <vector>


class Person {
public:
	Person(std::string);
	//Setters
	bool addCurrentAccount(int, double);
	bool addSavingsAccount(int, double, double*);
	bool closeAccount(int);
	bool depositMoney(int, double);
	bool withdrawMoney(int, double);
	//Getters
	std::string getName() const;
	double checkBalance(int);
	void printAllAccounts();

	void unableToLocateAccount(int);
	virtual ~Person();
private:
	const std::string name;
	const Date dob;
	std::vector<Account*> accounts;
};
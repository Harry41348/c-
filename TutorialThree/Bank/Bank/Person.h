#pragma once
#include "Account.h"
#include "Date.h"

#include <string>
#include <vector>


class Person {
public:
	Person(std::string);
	void addAccount(Account&);
	bool closeAccount(int*);
	void printAllAccounts();
	bool creditMoney(int*, double*);
	bool debitMoney(int*, double*);
	virtual ~Person();
private:
	const std::string name;
	const Date dob;
	std::vector<Account> accounts;
};


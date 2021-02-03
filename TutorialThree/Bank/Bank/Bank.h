#pragma once
#include "Person.h"

class Bank
{
public:
	Bank(std::string);
	//Setters
	bool registerPerson(std::string);
	bool newCurrentAccount(std::string, int, double);
	bool closeAccount(std::string, int);
	bool depositMoney(std::string, int, double);
	bool withdrawMoney(std::string, int, double);
	//Getters
	double checkBalance(std::string, int);
	void checkAccounts(std::string);

	void unableToFindAccountHolder(std::string);
private:
	std::string name;
	std::vector<Person> accountHolders;
};
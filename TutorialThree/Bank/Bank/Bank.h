#pragma once
#include "Person.h"

class Bank
{
public:
	Bank(std::string);
	//Setters
	bool registerPerson(std::string);
	bool newCurrentAccount(std::string, int, double);
	bool closeAccount(int, std::string);
	bool depositMoney();
	bool withdrawMoney();
	//Getters
	double checkBalance();
	void checkAccounts();
private:
	std::string name;
	std::vector<Person> accountHolders;
};
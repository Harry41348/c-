#pragma once
#include "Person.h"

class Bank
{
public:
	Bank(std::string);
	void registerPerson(std::string);
	bool newAccount(Account&);

private:
	std::string name;
	std::vector<Person> accountHolders;
};
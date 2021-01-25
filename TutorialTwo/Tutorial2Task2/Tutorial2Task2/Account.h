#pragma once
#include <string>

class Account
{
public:
	Account(std::string, double);
	void addCredit(double);
	void withdraw(double);
	double getBalance();
private:
	std::string name;
	double balance;
};


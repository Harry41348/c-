#pragma once
#include "Date.h"

#include <string>
#include <iostream>

class Account 
{
public:
	Account(int*, double*);

	bool withdraw(double*);
	bool credit(double*);

	int getAccNo();
	double getBal();
	std::string getDetails() const;
	double simulateInterest(int, double);
	static int getTotalAccounts();

	virtual ~Account();
	virtual double getBalance() = 0;
	virtual void printDetails() = 0;
private:
	const Date dateOpened;
	double balance;
	int accountNo;
	static int totalAccounts;
};

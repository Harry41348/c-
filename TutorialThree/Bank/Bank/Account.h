#pragma once
#include "Date.h"

#include <string>
#include <iostream>

class Account 
{
public:
	Account(int, double);
	//Setters
	bool deposit(double);
	bool withdraw(double);
	//Getters
	int getAccountNumber() const;
	double getBalance() const;
	std::string getDetails() const;
	static int getTotalAccounts();
	//Virtual
	virtual ~Account();
	virtual double getBalance() = 0;
	virtual void printDetails() = 0;
private:
	const Date dateOpened;
	double balance;
	int accountNo;
	static int totalAccounts;
};

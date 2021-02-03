#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(int, double);

	virtual double getBalance();
	virtual void printDetails();
};


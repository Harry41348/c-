#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(int, double);

	virtual double getBalance();
	virtual void printDetails();
};


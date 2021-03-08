#pragma once
#include "Account.h"

#include <Math.h>

class SavingsAccount : public Account
{
public:
	SavingsAccount(int, double, double*);
	void addYears(int);
	void setInterest(double*);

	double getInterestAmount() const;
	int getYears() const;


	virtual double getBalance();
	virtual void printDetails();
private:
	double interest;
	int years;
};


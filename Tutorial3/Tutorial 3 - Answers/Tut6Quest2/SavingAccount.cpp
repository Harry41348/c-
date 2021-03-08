
#include <string>
#include <sstream>
#include "SavingAccount.h"

// constructor initializes members
SavingAccount::SavingAccount(int* bal, double* accNo, const Date& doc, double IR)
	: Account(bal, accNo, doc) // initialize base class
{
	interestRate = (IR < 0.0) ? 0.0 : IR; 
	
} 



double SavingAccount::getBalance()
{
	return Account::getBalance() * getIRate();
} 
double SavingAccount::getIRate()
{
	return interestRate;
}

string SavingAccount::printDetails() const
{
	return "Return details";
}



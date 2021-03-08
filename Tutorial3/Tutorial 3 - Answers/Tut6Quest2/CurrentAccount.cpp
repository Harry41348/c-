#include "CurrentAccount.h"
#include <iostream>

using namespace std;

// constructor initializes balance and transaction fee
CurrentAccount::CurrentAccount(int* bal, double* accNo, const Date& doc)
    : Account(bal, accNo, doc) // initialize base class
{
} // end CheckingAccount constructor

double CurrentAccount::getBalance()
{
    return Account::getBalance();
}

string CurrentAccount::printDetails() const
{
    return "Return details";
}



#include "CurrentAccount.h"
#include "Account.h"

CurrentAccount::CurrentAccount(int accNo, double bal)
	: Account(accNo, bal){
}

double CurrentAccount::getBalance() {
	return Account::getBalance();
}

void CurrentAccount::printDetails() {
	std::cout << "Account number: " << Account::getAccountNumber() <<
		"\nBalance: " << getBalance() << std::endl;
}
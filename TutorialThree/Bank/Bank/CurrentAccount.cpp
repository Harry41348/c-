#include "CurrentAccount.h"
#include "Account.h"

CurrentAccount::CurrentAccount(int* accNo, double* bal)
	: Account(accNo, bal){

}

double CurrentAccount::getBalance() {
	return Account::getBal();
}

void CurrentAccount::printDetails() {
	std::cout << "Account number: " << Account::getAccNo <<
		"\nBalance: " << getBalance() << std::endl;
}
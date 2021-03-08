#include "SavingsAccount.h"
#include "Account.h"

#include <math.h>

SavingsAccount::SavingsAccount(int accNo, double bal, double *interest)
	: Account(accNo, bal) {
	this->interest = *interest;
	this->years = 0;
}

void SavingsAccount::addYears(int years) {
	if (years > 0) {
		this->years += years;
	}
	else {
		std::cout << "Years must be a positive number";
	}
}

void SavingsAccount::setInterest(double *interest) {
	if (*interest >= 1) {
		this->interest = *interest;
	}
	else {
		std::cout << "Interest must be a positive number of 1 or over.";
	}
}

double SavingsAccount::getInterestAmount() const {
	return this->interest;
}

int SavingsAccount::getYears() const {
	return this->years;
}

double SavingsAccount::getBalance() {
	double rtn = Account::getBalance * (pow(this->getInterestAmount, this->getYears));
	return rtn;
}

void SavingsAccount::printDetails() {
	std::cout << "Account number: " << Account::getAccountNumber() <<
		"\nBalance: " << getBalance() << std::endl;
}
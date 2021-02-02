#include "Account.h"

#include <string>
#include <iostream>
#include <sstream>

int Account::totalAccounts = 0;

//Constructor
Account::Account(int *accNo, double *bal) {

	this->accountNo = *accNo;
	++totalAccounts;

	if (bal < 0) {
		this->balance = 0;
		std::cout << "Error: balance needs to be a positive number. Balance has been set to 0.";
	}
	else {
		this->balance = *bal;
	}
}

//Setters
bool Account::credit(double * in) {
	if (in > 0) {
		this->balance += *in;
		return true;
	}
	return false;
}

bool Account::withdraw(double * in) {
	if (in > 0) {
		this->balance += *in;
		return true;
	}
	return false;
}

//Getters
std::string Account::getDetails() const {
	std::ostringstream conAcc, conBal;
	conAcc << this->accountNo;
	std::string toRet;
	toRet += "Accouunt No: ";
	toRet += conAcc.str();
	toRet += " Balance : ";
	conBal << this->balance;
	toRet += conBal.str();
	return toRet;
}

int Account::getAccNo()
{
	return this->accountNo;
}

double Account::getBal() {
	return this->balance;
}

int Account::getTotalAccounts() {
	return totalAccounts;
}

double Account::simulateInterest(int years, double interest) {
	double finalSum = this->balance;
	if (years != 0) {
		finalSum *= interest;
		finalSum = this->simulateInterest(years - 1, interest);
	}
	return finalSum;
}

//Deconstructor
Account::~Account() {

}
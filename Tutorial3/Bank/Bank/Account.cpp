#include "Account.h"

#include <string>
#include <iostream>
#include <sstream>

int Account::totalAccounts = 0;

//Constructor
Account::Account(int accNo, double bal) {
	this->accountNo = accNo;
	++totalAccounts;

	if (bal < 0) {
		this->balance = 0;
		std::cout << "Error: balance needs to be a positive number. Balance has been set to 0." << std::endl;
	}
	else {
		this->balance = bal;
	}
}

//Setters
bool Account::deposit(double in) {
	if (in > 0) {
		this->balance += in;
		std::cout << "Succesfully deposited £" << in << "into the account." << std::endl;
		return true;
	}
	std::cout << "The amount to deposit must be a positive amount." << std::endl;
	return false;
}

bool Account::withdraw(double in) {
	if (in > 0 && (this->balance-in)>=0) {
		this->balance -= in;
		return true;
	}
	return false;
}

//Getters
int Account::getAccountNumber() const { return this->accountNo; }

double Account::getBalance() const { return this->balance; }

int Account::getTotalAccounts() { return totalAccounts; }

std::string Account::getDetails() const {
	std::ostringstream conAcc, conBal;
	conAcc << this->accountNo;
	std::string toRet;
	toRet += "Accouunt No: " + conAcc.str();
	toRet += " Balance : " + conAcc.str();
	conBal << this->balance;
	toRet += conBal.str();
	return toRet;
}


//Deconstructor
Account::~Account() {

}
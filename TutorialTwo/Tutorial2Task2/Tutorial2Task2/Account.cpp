#include "Account.h"
#include <string>
#include <iostream>

Account::Account(std::string name, double amount) {
	Account::name = name;
	if (amount < 0) {
		balance = 0;
		std::cout << "Error: balance needs to be a positive number. Balance has been set to 0.";
	}
	balance = amount;
}

void Account::addCredit(double amount) {
	balance += amount;
}

void Account::withdraw(double amount) {
	balance -= amount;
}

double Account::getBalance() {
	return balance;
}
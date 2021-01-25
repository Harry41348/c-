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

void Account::simulateInterest(float interest, int years) {
	if (years != 0) {
		balance *= interest;
		this->simulateInterest(interest, years - 1);
	}
	else {
		std::cout << "Balance is now: " << balance;
	}
}
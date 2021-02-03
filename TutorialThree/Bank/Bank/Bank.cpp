#include "Bank.h"
#include "Account.h"

Bank::Bank(std::string bankName) :name(bankName){

}

bool Bank::registerPerson(std::string personsName) {
	for (Person person : accountHolders) {
		if (person.getName == personsName) {
			std::cout << "Name already exists." << std::endl;
			return false;
		}
	}
	Person newPerson = Person(personsName);
	accountHolders.push_back(newPerson);
	std::cout << personsName << " has been succesfully added to the bank" << std::endl;
	return true;
}

//Setters
bool Bank::newCurrentAccount(std::string name, int accountNumber, double balance) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			return person.addCurrentAccount(accountNumber, balance);
		}
	}
	return unableToFindAccountHolder(name);
}

bool Bank::closeAccount(std::string name, int accountNumber) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			return person.closeAccount(accountNumber);
		}
	}
	unableToFindAccountHolder(name);
	return false;
}

bool Bank::depositMoney(std::string name, int accountNumber, double amount) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			return person.depositMoney(accountNumber, amount);
		}
	}
	unableToFindAccountHolder(name);
	return false;
}

bool Bank::withdrawMoney(std::string name, int accountNumber, double amount) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			return person.withdrawMoney(accountNumber, amount);
		}
	}
	unableToFindAccountHolder(name);
	return false;
}

//Getters
double Bank::checkBalance(std::string name, int accountNumber) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			return person.checkBalance(accountNumber);
		}
	}
	unableToFindAccountHolder(name);
	return false;
}

void Bank::checkAccounts(std::string name) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			person.printAllAccounts();
		}
	}
	unableToFindAccountHolder(name);
}

void Bank::unableToFindAccountHolder(std::string name) {
	std::cout << "Unable to find an account holder with the name " << name << ".\n";
}
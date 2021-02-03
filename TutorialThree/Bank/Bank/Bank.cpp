#include "Bank.h"
#include "Account.h"

Bank::Bank(std::string bankName) :name(bankName){

}

bool Bank::registerPerson(std::string personsName) {
	for (Person person : accountHolders) {
		if (person.getName == personsName) {
			return false;
		}
	}
	Person newPerson = Person(personsName);
	accountHolders.push_back(newPerson);
	return true;
}

bool Bank::newCurrentAccount(std::string name, int accountNumber, double balance) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			return person.addCurrentAccount(accountNumber, balance);
		}
	}
	std::cout << "Unable to find account holder." << std::endl;
	return false;
}

bool Bank::closeAccount(int *acc, std::string name) {
	for (Person person : accountHolders) {
		if (person.getName == name) {
			person.closeAccount(acc);
			return true;
		}
	}
	return false;
}
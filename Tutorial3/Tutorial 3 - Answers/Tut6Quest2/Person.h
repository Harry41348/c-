/*
 * Person.h
 */

#ifndef BANKSOLUTION_SRC_PERSON_H_
#define BANKSOLUTION_SRC_PERSON_H_

#include <string>
#include <vector>
#include "Account.h"
#include "Date.h"


using namespace std;

class Person {
public:
	Person(string, const Date&);
	void addAccount(Account&);
	bool closeAccount(int*);
	void printAllAccounts();
	bool creditMoney(int*, double*);
	bool debitMoney(int*, double*);

	void printDate() const;

	virtual ~Person();

private:
	const string name;
	vector<Account> accounts;
	const Date dateOfBirth;
};

#endif /* BANKSOLUTION_SRC_PERSON_H_ */

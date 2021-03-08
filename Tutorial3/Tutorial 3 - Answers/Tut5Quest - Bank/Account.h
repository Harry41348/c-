
#include <string>
#include <vector>
#include "Date.h"
#include "Person.h"



#ifndef BANKSOLUTION_SRC_ACCOUNT_H_
#define BANKSOLUTION_SRC_ACCOUNT_H_

#include <string>

using namespace std;

class Account {
public:
	Account(int * , double * , const Date&);

	
	Account& operator = (const Account& source) 
	{ 
		// copy all other data
		return *this; 
	}
	

	static int getCount();
	bool debit(double *);
	bool credit(double *);
	int getAccNo();
	string getDetails() const;

	void printDate() const;

	virtual ~Account();



private:
	double balance;
	int accountNo;
	static int accountCount;
	const Date dateOfCreation;
};

#endif /* BANKSOLUTION_SRC_ACCOUNT_H_ */

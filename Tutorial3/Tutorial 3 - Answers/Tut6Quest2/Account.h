
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
	Account(int*, double*, const Date&);

	
	Account& operator = (const Account& source)
	{
		
		return *this;
	}
	

	static int getCount();
	bool debit(double*);
	bool credit(double*);
	int getAccNo();
	virtual double getBalance();
	virtual string printDetails() const = 0;

	void printDate() const;

	virtual ~Account();



private:
	double balance;
	int accountNo;
	static int accountCount;
	const Date date;
};

#endif /* BANKSOLUTION_SRC_ACCOUNT_H_ */

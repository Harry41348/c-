#include "Account.h" // Account class definition

class CurrentAccount : public Account
{
	public:
		// constructor initializes balance and transaction fee
		CurrentAccount(int* , double* , const Date& );

		double getBalance();
		string printDetails() const;

};


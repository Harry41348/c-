#include "Account.h" // Account class definition

class SavingAccount : public Account
{
public:
	SavingAccount(int* , double* , const Date& , double );

	double getIRate(); // determine interest owed
	double getBalance();
	string printDetails() const;
private:
	double interestRate; // interest rate (percentage) earned by account
}; // end class SavingsAccount

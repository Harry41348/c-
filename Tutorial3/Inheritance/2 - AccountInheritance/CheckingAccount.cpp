// CheckingAccount.cpp
// Member-function definitions for class CheckingAccount.
#include <iostream>
#include "CheckingAccount.h" 
using namespace std;

// constructor initializes balance and transaction fee
CheckingAccount::CheckingAccount( double initialBalance, double fee )
   : Account( initialBalance ) // initialize base class
{
   transactionFee = ( fee < 0.0 ) ? 0.0 : fee; 
}


void CheckingAccount::credit( double amount )
{
   Account::credit( amount ); 
   chargeFee();
} 


bool CheckingAccount::debit( double amount )
{
   bool success = Account::debit( amount ); 

   if ( success ) // if money was debited, charge fee and return true
   {
      chargeFee();
      return true;
   }
   else // otherwise, do not charge fee and return false
      return false;
} 

// subtract transaction fee
void CheckingAccount::chargeFee()
{
   Account::setBalance( getBalance() - transactionFee );
   cout << "$" << transactionFee << " transaction fee charged." << endl;
} 

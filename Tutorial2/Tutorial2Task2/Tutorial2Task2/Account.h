#pragma once

class Account
{
public:
	Account(std::string, double);
	void addCredit(double);
	void withdraw(double);
	double getBalance();
	void simulateInterest(float, int);
private:
	std::string name;
	double balance;
};


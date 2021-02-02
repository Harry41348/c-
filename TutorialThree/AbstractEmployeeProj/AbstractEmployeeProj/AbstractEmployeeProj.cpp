// AbstractEmployeeProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;
void virtualViaPointer(const Employee * const);
void virtualViaReference(const Employee &);

int main()
{
	//set floating-pint output formatting
	cout << fixed << setprecision(2);

	//create derived-class objects
	SalariedEmployee salariedEmp("John", "Smith", "AB 12 45 75 22 D", 07, 01, 2004, 800);

	HourlyEmployee hourlyEmp("Dave", "Jones", "AB 45 42 96 22 F", 07, 01, 2004, 16.75, 40);

	CommissionEmployee commissionEmp("Ryan", "Owen", "AB 45 22 47 19 C", 07, 01, 10000, .06);

	BasePlusCommissionEmployee basepluscommisionEmp("Ann", "Pickles", "AB 05 09 55 23 H", 07, 01, 2004, 5000, .04, 300);


	cout << "Employees processed individually using static binding\n" << endl;

	salariedEmp.print();
	cout << "\nearned GBP" << salariedEmp.earnings() << "\n\n";
	hourlyEmp.print();
	cout << "\nearned GBP" << hourlyEmp.earnings() << "\n\n";
	commissionEmp.print();
	cout << "\nearned GBP" << commissionEmp.earnings() << "\n\n";
	basepluscommisionEmp.print();
	cout << "\nearned GBP" << basepluscommisionEmp.earnings() << "\n\n";
	cout << "\n\n";

	//create a vector of four base-class pointers
	vector <Employee *> employees(4);

	//initialise the vector with Employees
	employees[0] = &salariedEmp;
	employees[1] = &hourlyEmp;
	employees[2] = &commissionEmp;
	employees[3] = &basepluscommisionEmp;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";

	cout << "Virtual function calls made off base-class pointers:\n\n";

	for (int i = 0; i < employees.size(); i++)
	{
		virtualViaPointer(employees[i]); //note dereferencing
	}

	cout << "Virtual function calls made off base-class references:\n\n";

	for (int i = 0; i < employees.size(); i++)
	{
		virtualViaReference(*employees[i]); //note dereferencing
	}

	cout << "Press any key to close" << endl;
	getchar(); // gets a character from the command line.
	return 0;
}

void virtualViaPointer(const Employee * const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned GBP " << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(const Employee &baseClassRef)
{
	baseClassRef.print();
	cout << "\nearned GBP " << baseClassRef.earnings() << "\n\n";
}
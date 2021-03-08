

#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int dy, int mn, int yr) {
	day = dy;
	month = mn;
	year = yr;
}


void Date::print() const
{
	cout << day << "/" << month << "/" << year << endl;
}


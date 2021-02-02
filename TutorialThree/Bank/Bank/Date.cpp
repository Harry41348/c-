#include "Date.h"

#include <iostream>

Date::Date(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
}

void Date::getDate() {
	std::cout << day << "/" << month << "/" << year << std::endl;
}
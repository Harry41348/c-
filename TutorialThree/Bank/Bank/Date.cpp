#include "Date.h"

#include <iostream>

Date::Date(int d, int m, int y) {
	this->day = d;
	this->month = m;
	this->year = y;
}

bool Date::setDate(int d, int m, int y) {
	if(d < 31 && m <= 12 && y <= 2021){
		this->day = d;
		this->month = m;
		this->year = y;
		return true;
	}
	else {
		return false;
	}
}

void Date::getDate() {
	std::cout << day << "/" << month << "/" << year << std::endl;
}
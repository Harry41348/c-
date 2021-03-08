#pragma once
#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(int = 1, int = 1, int = 1990);
	void print() const;

private:
	int day;
	int month;
	int year;
};

#endif /* DATE_H_ */

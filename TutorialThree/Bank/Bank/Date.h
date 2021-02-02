#pragma once
class Date
{
public:
	Date(int = 1, int = 1, int = 2000);
	bool setDate(int, int, int);
	void getDate();
private:
	int day;
	int month;
	int year;
};


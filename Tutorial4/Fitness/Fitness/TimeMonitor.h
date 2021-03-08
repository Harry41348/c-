#pragma once
#include "pch.h"
using namespace std;
class TimeMonitor {
public:
	TimeMonitor(int = 0, int = 0, int = 0);
	virtual ~TimeMonitor();

	int hour;
	int min;
	int sec;

	void setTime(int h, int m, int s);
	void increment();
	void printTime();

	int getHour();
	int getMin();
	int getSec();

	void attach(class Observer *obs);
	void notify();
private:
	vector <class Observer *> views;
};


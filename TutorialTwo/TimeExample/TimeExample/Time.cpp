#include "pch.h"
#include "Time.h"

using namespace std;

Time::Time()
{
	hour = minute = second = 0;
}


Time::~Time()
{
}

void Time::setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
	//call the print time method.
	printTime();
}

//print time in 24 hour format (HH:MM:SS)
void Time::printTime()
{
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
}

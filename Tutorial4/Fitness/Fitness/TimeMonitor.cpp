#include "pch.h"
#include "TimeMonitor.h"
#include "Observer.h"

using namespace std;

TimeMonitor::TimeMonitor(int h, int m, int s) {
	setTime(h, m, s);

}

TimeMonitor::~TimeMonitor() {
	// TODO Auto-generated destructor stub
}

void TimeMonitor::setTime(int h, int m, int s)
{
	this->hour = (h >= 0 && h < 24) ? h : 0;
	this->min = (m >= 0 && m < 60) ? m : 0;
	this->sec = (s >= 0 && s < 60) ? s : 0;
}


void TimeMonitor::increment()
{
	sec = (sec + 1) % 60;//add one second, or roll over
	if (sec == 0) //rolled over, add 1 minute
	{
		min = (min + 1) % 60;//add one minute, or roll over
		notify(); //notify any listeners for a change
		if (min == 0)
		{
			hour = (hour + 1) % 24;
		}
	}

}

int TimeMonitor::getHour()
{
	return hour;
}

int TimeMonitor::getMin()
{
	return min;
}

int TimeMonitor::getSec()
{
	return sec;
}

void TimeMonitor::printTime()
{
	cout << setfill('0') << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec << endl;;
}

void TimeMonitor::attach(Observer *obs)
{
	views.push_back(obs);
}
void TimeMonitor::notify()
{
	for (int i = 0; i < views.size(); i++)
	{
		views[i]->update();
	}
}

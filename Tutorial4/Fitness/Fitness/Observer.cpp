#include "pch.h"
#include "Observer.h"


Observer::Observer(TimeMonitor *t) {
	time = t;
	time->attach(this);
}

Observer::~Observer() {
	// TODO Auto-generated destructor stub

	std::cout << "Goodbye, I was an Observer.";
}

TimeMonitor *Observer::getTime()
{
	return time;
}
#pragma once
#include "TimeMonitor.h"

class Observer {
public:
	Observer(TimeMonitor *t);
	virtual ~Observer();

	virtual void update() = 0;
	TimeMonitor *time;
	TimeMonitor *getTime();
};


#pragma once
#include "Observer.h"

class Distance : public Observer
{
public:
	Distance(TimeMonitor* t);
	virtual ~Distance();
	virtual void update();

private:
	double distance;
	double averageMph;
	int durationInMins;
};

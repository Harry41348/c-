#pragma once
#include "Observer.h"

class HeartRate : public Observer
{
public:
	HeartRate(TimeMonitor* t);
	virtual ~HeartRate();
	virtual void update();

private:
	int durationInMins;
	double beatsPerMin;
	int totalBeats;
};


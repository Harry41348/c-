#pragma once
#include "Observer.h"

class Calories : public Observer {
public:
	Calories(TimeMonitor *t);
	virtual ~Calories();
	virtual void update();

private:
	int durationInMins = 0;
	double caloriesPerMin = 80;
	double totalCaloriesBurnt;
};
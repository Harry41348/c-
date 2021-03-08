#include "pch.h"
#include "Calories.h"


using namespace std;
Calories::Calories(TimeMonitor *t) : Observer(t)
{
	//	startTimeInMins = ((getTime()->hour)*60) + (getTime()->min);

}

//pull information of interest
void Calories::update()
{
	durationInMins++;
	//cout << "Mins " << durationInMins;
	totalCaloriesBurnt = caloriesPerMin * durationInMins;
	cout << "Total Calories Burnt: " << totalCaloriesBurnt << endl;
}

Calories::~Calories() {
	// TODO Auto-generated destructor stub
}

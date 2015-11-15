#include "Robot.h"

void Robot::prepare(long waitingTime)
{
	long numMeasure = 0;
	long startingTime = millis();

	while(millis() < startingTime + waitingTime) {
		if(millis() > startingTime + waitingTime / 2) {
			for (unsigned i = 0; i < Robot::infraredSensors.size(); ++i)
			{
				Robot::infraredSensors[i].setDefaultVal((Robot::infraredSensors[i].getDefaultVal() * numMeasure + Robot::infraredSensors[i].getValue()) / (numMeasure + 1));
			}
			for (unsigned i = 0; i < Robot::lineSensors.size(); ++i)
			{
				Robot::lineSensors[i].setDefaultVal((Robot::lineSensors[i].getDefaultVal() * numMeasure + Robot::lineSensors[i].getValue()) / (numMeasure + 1));
			}
		}
	}
}
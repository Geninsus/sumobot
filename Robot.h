#ifndef Robot_h
#define Robot_h

#include <vector>

#include "Arduino.h"
#include "Led.h"
#include "Motor.h"
#include "InfraredSensor.h"
#include "LineSensor.h"

enum	{start};

class Robot
{
public:
	static void prepare(long waitingTime);
	static int state;
private:
	static std::vector<Motor> motors;
	static std::vector<InfraredSensor> infraredSensors;
	static std::vector<LineSensor> lineSensors;
	static std::vector<Led> leds;
};

#endif

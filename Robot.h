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
	static int state;
	static Motor motorLeft;
	static Motor motorRight;
	static std::vector<InfraredSensor> infraredSensors;
	static std::vector<LineSensor> lineSensors;
	static std::vector<Led> leds;

	static void prepare(long waitingTime);
	static void forward();
	static void backward();
	static void left();
	static void right();
};

#endif

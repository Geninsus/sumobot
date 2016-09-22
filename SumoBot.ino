#include <StandardCplusplus.h>

#include <vector>

#include "Led.h"
#include "Motor.h"
#include "InfraredSensor.h"
#include "LineSensor.h"

#include "Robot.h"

std::vector<InfraredSensor> Robot::infraredSensors = {
	InfraredSensor(0),
	InfraredSensor(1),
	InfraredSensor(2),
	InfraredSensor(3),
	InfraredSensor(4),
	InfraredSensor(5)
};

std::vector<LineSensor> Robot::lineSensors = {
	LineSensor(8),
	LineSensor(9),
	LineSensor(10),
	LineSensor(11)
};

std::vector<Motor> Robot::motors = {
	Motor(0, 1, 6),
	Motor(2, 3, 7)
};

std::vector<Led> Robot::leds = {
	Led(4),
	Led(5),
	Led(6),
	Led(7)
};

int Robot::state = start;

void setup()
{
	// prepare
}

void loop()
{
	// search
	switch(Robot::state) {
		case start:
			break;
	}
}

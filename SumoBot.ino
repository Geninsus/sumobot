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
	InfraredSensor(3)
};

std::vector<LineSensor> Robot::lineSensors = {
	LineSensor(8),
	LineSensor(9),
	LineSensor(10),
	LineSensor(11)
};

Motor Robot::motorLeft = Motor(6, 7, 11);
Motor Robot::motorRight = Motor(8, 9, 10);

std::vector<Led> Robot::leds = {
	Led(4),
	Led(5),
	Led(6),
	Led(7)
};

int Robot::state = start;

void setup()
{
}

void loop()
{
	switch(Robot::state) {

		case start:
			Robot::prepare(5000);
			Robot::state = searchEnnemy;
			break;

		case searchEnnemy:
			Robot::searchEnnemy();
			break;
	}

}

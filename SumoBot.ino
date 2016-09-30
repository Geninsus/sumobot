#include <StandardCplusplus.h>

#include <vector>

#include "Led.h"
#include "Motor.h"
#include "InfraredSensor.h"
#include "LineSensor.h"

#include "Robot.h"

enum direction {front, back, left, right};

std::vector<InfraredSensor> Robot::infraredSensors = {
	InfraredSensor(4)
};

std::vector<LineSensor> Robot::lineSensors = {
	LineSensor(0),
	LineSensor(1)
};

Motor Robot::motorLeft = Motor(6, 7, 11);
Motor Robot::motorRight = Motor(8, 9, 10);

std::vector<Led> Robot::leds = {
	Led(13)
};

int Robot::state = start;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	switch(Robot::state) {

		case start:
			Robot::prepare(5000);
			Robot::state = testLineSensors;
			break;

		case searchEnnemy:
			Robot::searchEnnemy();
			break;

		case testLineSensors:
			Robot::testLineSensors();
			break;
	}

}

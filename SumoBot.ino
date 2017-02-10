#include <StandardCplusplus.h>

#include <vector>

#include "Led.h"
#include "Motor.h"
#include "InfraredSensor.h"
#include "LineSensor.h"

#include "Robot.h"

#define WAIT_TIME 5000

std::vector<InfraredSensor> Robot::infraredSensors = {
	InfraredSensor(A0),
	InfraredSensor(A1),
	InfraredSensor(A2),
	InfraredSensor(A3)
};

std::vector<LineSensor> Robot::lineSensors = {
	LineSensor(2),
	LineSensor(5),
	LineSensor(3),
	LineSensor(4)
};

Motor Robot::motorLeft = Motor(6, 7, 11);
Motor Robot::motorRight = Motor(8, 9, 10);

//std::vector<Led> Robot::leds = {
	//Led(13)
//};

int Robot::state = start;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	switch(Robot::state) {

		case start:
			Robot::prepare(WAIT_TIME);
			Robot::state = searchEnnemy;
			break;

		case searchEnnemy:
			Robot::escapeLine();
			Robot::searchEnnemy();
			break;

		case test:
			//Robot::test();
			break;
	}
}

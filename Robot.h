#ifndef Robot_h
#define Robot_h

#include <vector>

#include "Arduino.h"
#include "Led.h"
#include "Motor.h"
#include "InfraredSensor.h"
#include "LineSensor.h"

enum	{start, searchEnnemy, test};

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
	static void searchEnnemy();
	static void escapeLine();
	static std::vector<bool> detectEnnemy();
  static std::vector<bool> detectLine();
	static void test();
	static void go(int angle, bool reverse);
	static void forward(int angle);
	static void backward(int angle);
	static void left();
	static void right();
};

#endif

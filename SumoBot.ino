#include "Led.h"
#include "Motor.h"
#include "InfraredSensor.h"

void setup()
{
	/**
	 * Exemple d'utilisation de la classe Led
	 */

	Led led1(2);
	led1.setState(1);

	 /**
	  * Exemple d'utilisation de la classe Motor
	  */

	 Motor motor1(1, 2, 3);

	 motor1.setDirection(1);
	 motor1.setValue(255);
}

void loop()
{

}

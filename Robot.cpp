#include "Robot.h"

/**
 * Préparation du robot et temps d'attentes
 *
 * @param waitingTime Temps d'attente
 */
void Robot::prepare(long waitingTime)
{
	long numMeasure = 0;
	long startingTime = millis();

	// Tant que le temps d'attente n'est pas écoulé
	while(millis() < startingTime + waitingTime) {
		// À la mi-temps on initialise les capteurs
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

/**
 * Avancer
 */
void Robot::forward()
{
	Robot::motorLeft.setDirection(direction::forward);
	Robot::motorRight.setDirection(direction::forward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Reculer
 */
void Robot::backward()
{
	Robot::motorLeft.setDirection(direction::backward);
	Robot::motorRight.setDirection(direction::backward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Tourner vers la gauche
 */
void Robot::left()
{
	Robot::motorLeft.setDirection(direction::backward);
	Robot::motorRight.setDirection(direction::forward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Tourner vers la droite
 */
void Robot::right()
{
	Robot::motorLeft.setDirection(direction::forward);
	Robot::motorRight.setDirection(direction::backward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

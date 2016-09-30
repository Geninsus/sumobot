#include "Robot.h"

/**
 * Préparation du robot et temps d'attentes
 *
 * @param waitingTime Temps d'attente en ms
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
				// On affine la valeur par défaut de chaque capteurs infrarouge
				Robot::infraredSensors[i].setDefaultVal((Robot::infraredSensors[i].getDefaultVal() * numMeasure + Robot::infraredSensors[i].getValue()) / (numMeasure + 1));
			}
			for (unsigned i = 0; i < Robot::lineSensors.size(); ++i)
			{
				// On affine la valeur par défaut de chaque capteurs de ligne
				Robot::lineSensors[i].setDefaultVal((Robot::lineSensors[i].getDefaultVal() * numMeasure + Robot::lineSensors[i].getValue()) / (numMeasure + 1));
			}
			numMeasure++;
		}
	}
	for (unsigned i = 0; i < Robot::lineSensors.size(); ++i)
	{
			Serial.print("LineSensors ");
			Serial.print(i);
			Serial.print(": ");
			Serial.println(Robot::lineSensors[i].getDefaultVal());
	}

}

/**
 * Recherche l'ennemi
 */
void Robot::searchEnnemy()
{
		Robot::left();
		if(Robot::detectEnnemy()) {

		}
}

/**
 * Détecte l'ennemi le plus proche
 * @return Distance à l'ennemi, -1 si pas d'ennemi
 */
int Robot::detectEnnemy()
{
	for(unsigned i = 0; i < Robot::infraredSensors.size(); i++) {
		if(Robot::infraredSensors[i].detectEnnemy()) {
			// BLa bla
		}
	}
	return -1;
}

void Robot::testLineSensors()
{
	for (unsigned i = 0; i < Robot::lineSensors.size(); ++i)
	{
			Serial.print(i);
			if(Robot::lineSensors[i].isBlack())
			{
				Serial.println(" - Black");
			} else {
				Serial.println(" - White");
			}
	}
	Serial.println("");
	delay(1000);
}

/**
 * Avancer
 */
void Robot::forward()
{
	Robot::motorLeft.setDirection(rotationDirection::forward);
	Robot::motorRight.setDirection(rotationDirection::forward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Reculer
 */
void Robot::backward()
{
	Robot::motorLeft.setDirection(rotationDirection::backward);
	Robot::motorRight.setDirection(rotationDirection::backward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Tourner vers la gauche
 */
void Robot::left()
{
	Robot::motorLeft.setDirection(rotationDirection::backward);
	Robot::motorRight.setDirection(rotationDirection::forward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Tourner vers la droite
 */
void Robot::right()
{
	Robot::motorLeft.setDirection(rotationDirection::forward);
	Robot::motorRight.setDirection(rotationDirection::backward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

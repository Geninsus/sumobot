#include "Robot.h"

/**
 * Préparation du robot et temps d'attentes
 *
 * @param waitingTime Temps d'attente en ms
 */
void Robot::prepare(long waitingTime)
{
	long startingTime = millis();

	// Tant que le temps d'attente n'est pas écoulé
	while(millis() < startingTime + waitingTime) {

	}
}

/**
 * Recherche l'ennemi
 */
void Robot::searchEnnemy()
{
		int enemy = Robot::detectEnnemy();
		switch (enemy) {
			case 0:
				Robot::forward();
				break;
			case 1:
				Robot::forward();
				break;
			case 2:
				Robot::forward();
				break;
			case 3:
				Robot::forward();
				break;
			default:
				Robot::left();
		}
}

/**
 * Test les capteurs et moteurs
 */
void Robot::test()
{
	if(Robot::lineSensors[0].isWhite()) Robot::backward();
	if(Robot::lineSensors[1].isWhite()) Robot::backward();
	if(Robot::lineSensors[2].isWhite()) Robot::forward();
	if(Robot::lineSensors[3].isWhite()) Robot::forward();
}

/**
 * Détecte un enemi
 * @return id du capteur, -1 si pas d'ennemi
 */
int Robot::detectEnnemy()
{
	for(unsigned i = 0; i < Robot::infraredSensors.size(); i++) {
		if(Robot::infraredSensors[i].detectEnnemy()) {
			return i;
		}
	}
	return -1;
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

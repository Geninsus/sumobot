#include "Robot.h"

#define awayTime 1200

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
		std::vector<bool> enemiesDetection = Robot::detectEnnemy();

		// Si ennemi avant
		if(enemiesDetection[0] && enemiesDetection[1]) {
			Robot::forward(90);

		// Si ennemi arrière
		} else if(enemiesDetection[2] && enemiesDetection[3]) {
			Robot::backward(90);

		// Si ennemi avant gauche
		} else if(enemiesDetection[0]) {
			Robot::forward(30);

		// Si ennemi avant droite
		} else if(enemiesDetection[1]) {
			Robot::forward(150);


		// Si ennemi arrière gauche
		} else if(enemiesDetection[2]) {
			Robot::backward(150);


		// Si ennemi arrière droite
		} else if(enemiesDetection[3]) {
			Robot::backward(30);

		// Sinon cherhe ennemi
		} else {
			Robot::left();
		}
}

/**
 * Evite les lignes
 */
void Robot::escapeLine()
{
		std::vector<bool> linesDetection = Robot::detectLine();

		// Si ligne avant
		if(linesDetection[0] && linesDetection[1]) {
			Robot::backward(90);
			delay(3000);

		// Si ligne arrière
		} else if(linesDetection[2] && linesDetection[3]) {
			Robot::forward(90);
			delay(3000);

		// Si ligne avant gauche
		} else if(linesDetection[0]) {
			Robot::backward(30);
			delay(3000);

		// Si ligne avant droite
		} else if(linesDetection[1]) {
			Robot::backward(150);
			delay(3000);


		// Si ligne arrière gauche
		} else if(linesDetection[2]) {
			Robot::forward(150);
			delay(3000);


		// Si ligne arrière droite
		} else if(linesDetection[3]) {
			Robot::forward(30);
			delay(3000);
		}
}

/**
 * Détecte un enemi
 * @return id du capteur, -1 si pas d'ennemi
 */
std::vector<bool> Robot::detectEnnemy()
{
	std::vector<bool> enemiesDetection;
	for(unsigned i = 0; i < Robot::infraredSensors.size(); i++) {
		enemiesDetection.push_back(Robot::infraredSensors[i].detectEnnemy());
	}
	return enemiesDetection;
}

/**
 * Détecte une ligne
 * @return id du capteur, -1 si pas de ligne
 */
std::vector<bool> Robot::detectLine()
{
	std::vector<bool> linesDetection;
	for(unsigned i = 0; i < Robot::lineSensors.size(); i++) {
		linesDetection.push_back(Robot::lineSensors[i].isWhite());
	}
	return linesDetection;
}

/**
 * Avancer
 */
void Robot::go(int angle, bool reverse)
{
	if(angle == 90) {
		Robot::motorLeft.setPower(255);
		Robot::motorRight.setPower(255);
	} else if (angle < 90) {
		Robot::motorLeft.setPower(angle*255/90);
		Robot::motorRight.setPower(255);
	} else {
		Robot::motorLeft.setPower(255);
		Robot::motorRight.setPower(angle*255/90);
	}

	if(reverse) {
		Robot::motorLeft.setDirection(rotationDirection::backward);
		Robot::motorRight.setDirection(rotationDirection::backward);
	} else {
		Robot::motorLeft.setDirection(rotationDirection::forward);
		Robot::motorRight.setDirection(rotationDirection::forward);
	}
}

/**
 * Avancer
 */
void Robot::forward(int angle)
{
	Robot::go(angle, 0);
}

/**
 * Reculer
 */
void Robot::backward(int angle)
{
	Robot::go(angle, 1);
}

/**
 * Tourner vers la gauche
 */
void Robot::left()
{
	Robot::motorLeft.setDirection(rotationDirection::forward);
	Robot::motorRight.setDirection(rotationDirection::backward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

/**
 * Tourner vers la droite
 */
void Robot::right()
{
	Robot::motorLeft.setDirection(rotationDirection::backward);
	Robot::motorRight.setDirection(rotationDirection::forward);
	Robot::motorLeft.setPower(255);
	Robot::motorRight.setPower(255);
}

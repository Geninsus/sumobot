#include "InfraredSensor.h"

/**
 * Constructeur de InfraredSensor
 *
 * @param pin Numéro de pin associé
 */
InfraredSensor::InfraredSensor(unsigned char pin) : mPin(pin)
{
	pinMode(mPin, INPUT);
}

/**
 * Détecte un ennemi
 * @return bool True si un ennemi est détecté par le capteur, false sinon
 */
bool InfraredSensor::detectEnnemy()
{
	return !digitalRead(mPin);
}

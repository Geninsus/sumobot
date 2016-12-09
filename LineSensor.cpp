#include "LineSensor.h"

/**
 * Constructeur de LineSensor
 *
 * @param pin Numéro de pin associé
 */
LineSensor::LineSensor(unsigned char pin) : mPin(pin)
{
	pinMode(mPin, INPUT);
}

/**
 * Couleur blanc détécté par le capteur
 *
 * @return bool Est-il noir
 */
bool LineSensor::isWhite() const
{
	return digitalRead(mPin);
}

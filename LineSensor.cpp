#include "LineSensor.h"

/**
 * Constructeur de LineSensor
 *
 * @param pin Numéro de pin associé
 */
LineSensor::LineSensor(unsigned char pin) : mPin(pin), mDefaultVal(0)
{
	pinMode(mPin, INPUT);
}

 /**
  * Retourne la valeur du capteur
  *
  * @return unsigned char Valeur du capteur
  */
unsigned char LineSensor::getValue() const
{
	return analogRead(getPin());
}

/**
 * Modifie la valeur par défaut (au début du combat) du capteur
 *
 * @param defaultVal Valeur par défaut
 */
void LineSensor::setDefaultVal(const unsigned char& defaultVal)
{
  mDefaultVal = defaultVal;
}

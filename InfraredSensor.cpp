#include "InfraredSensor.h"

/**
 * Constructeur de InfraredSensor
 *
 * @param pin Numéro de pin associé
 */
InfraredSensor::InfraredSensor(unsigned char pin) : mPin(pin), mDefaultVal(0)
{
	pinMode(mPin, INPUT);
}

 /**
  * Retourne la valeur du capteur
  *
  * @return unsigned char Valeur du capteur
  */
unsigned char InfraredSensor::getValue() const
{
	return analogRead(getPin());
}

 /**
  * Retourne la valeur du capteur en cm
  *
  * @return int Valeur du capteur convertie en cm
  */
int InfraredSensor::getValueCm() const
{
	return 4800/(getValue() - 20);
}

/**
 * Modifie la valeur par défaut (au début du combat) du capteur
 *
 * @param defaultVal Valeur par défaut
 */
void InfraredSensor::setDefaultVal(const unsigned char& defaultVal)
{
  mDefaultVal = defaultVal;
}

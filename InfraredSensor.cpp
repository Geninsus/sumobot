#include "InfraredSensor.h"

/**
 * @brief Constructeur de InfraredSensor
 * 
 * @param unsigned char Numéro de pin associé
 */
InfraredSensor::InfraredSensor(const unsigned char &pin) : mPin(pin)
{
	pinMode(mPin, INPUT);
}

 /**
  * @brief Retourne la valeur du capteur
  * 
  * @return unsigned char Valeur du capteur
  */
unsigned char InfraredSensor::getValue() const
{
	return analogRead(getPin());
}

 /**
  * @brief Retourne la valeur du capteur en cm
  *
  * @return int Valeur du capteur convertie en cm
  */
int InfraredSensor::getValueCm() const
{
	return 4800/(getValue() - 20);
}
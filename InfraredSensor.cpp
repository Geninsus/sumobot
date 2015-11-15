#include "InfraredSensor.h"

/**
 * @brief Constructeur de InfraredSensor
 * 
 * @param unsigned char Numéro de pin associé
 */
InfraredSensor::InfraredSensor(unsigned char pin) : mPin(pin), mDefaultVal(0)
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

/**
 * @brief Modifie la valeur par défaut (au début du combat) du capteur
 * 
 * @param char Valeur par défaut
 */
void InfraredSensor::setDefaultVal(unsigned char defaultVal)
{
  mDefaultVal = defaultVal;
}
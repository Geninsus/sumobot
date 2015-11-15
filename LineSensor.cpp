#include "LineSensor.h"

/**
 * @brief Constructeur de LineSensor
 * 
 * @param unsigned char Numéro de pin associé
 */
LineSensor::LineSensor(unsigned char pin) : mPin(pin), mDefaultVal(0)
{
	pinMode(mPin, INPUT);
}

 /**
  * @brief Retourne la valeur du capteur
  * 
  * @return unsigned char Valeur du capteur
  */
unsigned char LineSensor::getValue() const
{
	return analogRead(getPin());
}

/**
 * @brief Modifie la valeur par défaut (au début du combat) du capteur
 * 
 * @param char Valeur par défaut
 */
void LineSensor::setDefaultVal(unsigned char defaultVal)
{
  mDefaultVal = defaultVal;
}
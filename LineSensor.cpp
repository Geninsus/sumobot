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
 * Couleur noir détécté par le capteur
 *
 * @return bool Est-il noir
 */
bool LineSensor::isBlack() const
{
	unsigned char value =  getValue();
	if((float)(getDefaultVal() - value) / (float)value > sensitivity) {
		return 0; // Blanc
	} else {
		return 1; // Noir
	}
}

 /**
  * Retourne la valeur du capteur
  *
  * @return unsigned char Valeur du capteur
  */
unsigned char LineSensor::getValue() const
{
	int result = 0;
	for(int i = nbMeasurement; i--;) {
		result += analogRead(getPin());
	}
	return result / nbMeasurement;
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

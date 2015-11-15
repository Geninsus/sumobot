#include "Led.h"

/**
 * @brief Constructeur de Led
 * 
 * @param char Numéro de pin associé
 */
Led::Led(unsigned char pin) : mPin(pin) {
	pinMode(mPin, OUTPUT);

	setState(0);
}

/**
 * @brief Modifie l'état de la led
 * 
 * @param bool Etat à prendre. 0: Eteind 1: Allumé
 */
void Led::setState(bool state)
{
	mState = state;

	digitalWrite(mPin, mState ? HIGH : LOW);
}
#include "Led.h"

/**
 * @brief Constructeur de Led
 * 
 * @param char Numéro de pin associé
 */
Led::Led(const unsigned char &pin) : mPin(pin) {
	pinMode(mPin, OUTPUT);

	setState(0);
}

/**
 * @brief Modifie l'état de la led
 * 
 * @param bool Etat à prendre. 0: Eteind 1: Allumé
 */
void Led::setState(const bool &state)
{
	mState = state;

	digitalWrite(mPin, mState);
}
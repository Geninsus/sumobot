#include "Led.h"

/**
 * Constructeur de Led
 *
 * @param pin Numéro de pin associé
 */
Led::Led(unsigned char pin) : mPin(pin) {
	pinMode(mPin, OUTPUT);

	setState(0);
}

/**
 * Modifie l'état de la led
 *
 * @param state Etat à prendre. 0: Eteind 1: Allumé
 */
void Led::setState(const bool& state)
{
	mState = state;

	digitalWrite(mPin, mState ? HIGH : LOW);
}

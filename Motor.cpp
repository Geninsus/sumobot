#include "Motor.h"

/**
 * Constructeur de Motor
 *
 * @param input1 Pin associée à l'entrée 1 du moteur
 * @param input2 Pin associée à l'entrée 2 du moteur
 * @param enable Pin associée à l'entrée enable du moteur. ex 0: Moteur à l'arret  127: Moteur à mi-puissance 255: Moteur à puissance maximale
 */
Motor::Motor(unsigned char input1, unsigned char input2, unsigned char enable) : mInput1(input1), mInput2(input2), mEnable(enable)
{
	pinMode(mInput1, OUTPUT);
	pinMode(mInput2, OUTPUT);
	pinMode(mEnable, OUTPUT);

	setValue(0);
	setDirection(1);
}

/**
 * Modifie la puissance du moteur
 * @param value Valeur de la puissance du moteur. ex 0: Moteur à l'arret  127: Moteur à mi-puissance 255: Moteur à puissance maximale
 */
void Motor::setValue(const unsigned char& value)
{
	mValue = value;
	analogWrite(mEnable, mValue);
}

/**
 * Modifie le sens du moteur
 *
 * @param direction Sens du moteur
 */
void Motor::setDirection(const bool& direction)
{
	mDirection = direction;
	digitalWrite(mInput1, mDirection ? HIGH : LOW);
	digitalWrite(mInput2, mDirection ? LOW : HIGH);
}

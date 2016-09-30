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

	setPower(0);
	setDirection(forward);
}

/**
 * Modifie la puissance du moteur
 * @param power Valeur de la puissance du moteur. ex 0: Moteur à l'arret  127: Moteur à mi-puissance 255: Moteur à puissance maximale
 */
void Motor::setPower(const unsigned char& power)
{
	mPower = power;
	analogWrite(mEnable, mPower);
}

/**
 * Modifie le sens du moteur
 *
 * @param direction Sens du moteur: forward | backward
 */
void Motor::setDirection(const rotationDirection& d)
{
	mDirection = d;
	digitalWrite(mInput1, mDirection ? HIGH : LOW);
	digitalWrite(mInput2, mDirection ? LOW : HIGH);
}

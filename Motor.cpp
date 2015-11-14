#include "Motor.h"

/**
 * @brief Constructeur de Motor
 * 
 * @param char Pin associée à l'entrée 1 du moteur
 * @param char Pin associée à l'entrée 2 du moteur
 * @param char Pin associée à l'entrée enable du moteur. ex 0: Moteur à l'arret  127: Moteur à mi-puissance 255: Moteur à puissance maximale
 */
Motor::Motor(const unsigned char &input1, const unsigned char &input2, const unsigned char &enable) : mInput1(input1), mInput2(input2), mEnable(enable)
{
	pinMode(mInput1, OUTPUT);
	pinMode(mInput2, OUTPUT);
	pinMode(mEnable, OUTPUT);
}

/**
 * @brief Modifie la puissance du moteur
 * 
 * @param char Valeur de la puissance du moteur. ex 0: Moteur à l'arret  127: Moteur à mi-puissance 255: Moteur à puissance maximale
 */
void Motor::setValue(const unsigned char &value)
{
	mValue = value;
	analogWrite(mEnable, mValue);
}

/**
 * @brief Modifie le sens du moteur
 * 
 * @param bool Sens du moteur
 */
void Motor::setDirection(const bool &direction)
{
	mDirection = direction;
	digitalWrite(mInput1, mDirection);
	digitalWrite(mInput2, !mDirection);
}

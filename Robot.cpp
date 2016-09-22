#include "Robot.h"

/**
 * @brief Préparation du robot et temps d'attentes
 *
 * @param waitingTime Temps d'attente
 */
void Robot::prepare(long waitingTime)
{
	long numMeasure = 0;
	long startingTime = millis();

	// Tant que le temps d'attente n'est pas écoulé
	while(millis() < startingTime + waitingTime) {
		// À la mi-temps on initialise les capteurs
		if(millis() > startingTime + waitingTime / 2) {
			for (unsigned i = 0; i < Robot::infraredSensors.size(); ++i)
			{
				Robot::infraredSensors[i].setDefaultVal((Robot::infraredSensors[i].getDefaultVal() * numMeasure + Robot::infraredSensors[i].getValue()) / (numMeasure + 1));
			}
			for (unsigned i = 0; i < Robot::lineSensors.size(); ++i)
			{
				Robot::lineSensors[i].setDefaultVal((Robot::lineSensors[i].getDefaultVal() * numMeasure + Robot::lineSensors[i].getValue()) / (numMeasure + 1));
			}
		}
	}
}

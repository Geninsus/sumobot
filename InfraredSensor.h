#ifndef InfraredSensor_h
#define InfraredSensor_h

#include "Arduino.h"

class InfraredSensor
{
public:
    InfraredSensor(unsigned char pin);

    bool detectEnnemy();
    unsigned char getPin() const {return mPin;}

private:
    unsigned char mPin;
};

#endif

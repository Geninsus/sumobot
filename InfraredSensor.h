#ifndef InfraredSensor_h
#define InfraredSensor_h

#include "Arduino.h"

class InfraredSensor
{
public:
    InfraredSensor(const unsigned char &pin);

    unsigned char getValue() const;
    int getValueCm() const;
    unsigned char getPin() const {return mPin;}
private:
    unsigned char mPin;
};

#endif
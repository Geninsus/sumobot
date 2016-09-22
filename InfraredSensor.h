#ifndef InfraredSensor_h
#define InfraredSensor_h

#include "Arduino.h"

class InfraredSensor
{
public:
    InfraredSensor(unsigned char pin);

    bool detectEnnemy();

    void setDefaultVal(const unsigned char& defaultVal);

    unsigned char getPin() const {return mPin;}
    unsigned char getDefaultVal() const {return mDefaultVal;}
    unsigned char getValue() const;
    int getValueCm() const;

private:
    unsigned char mPin;
    unsigned char mDefaultVal;

};

#endif

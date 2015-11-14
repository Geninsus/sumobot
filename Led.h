#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led
{
public:
    Led(const unsigned char &pin);

    void setState(const bool &state);

    unsigned char getPin() {return mPin;}
    bool getState() {return mState;}
private:
    unsigned char mPin;
    bool mState;
};

#endif

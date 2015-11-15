#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led
{
public:
    Led(const unsigned char &pin);

   	void on() {setState(1);}
    void off() {setState(0);}

    unsigned char getPin() {return mPin;}
    bool getState() {return mState;}
private:
    unsigned char mPin;
    bool mState;
    
    void setState(const bool &state);
};

#endif

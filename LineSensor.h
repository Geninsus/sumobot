#ifndef LineSensor_h
#define LineSensor_h

#include "Arduino.h"

class LineSensor
{
public:
  LineSensor(unsigned char pin);

  unsigned char getValue() const;

	void setDefaultVal(const unsigned char& defaultVal);

  unsigned char getPin() const {return mPin;}
  unsigned char getDefaultVal() const {return mDefaultVal;}
private:
  unsigned char mPin;
  unsigned char mDefaultVal;
};

#endif

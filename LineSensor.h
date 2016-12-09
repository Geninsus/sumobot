#ifndef LineSensor_h
#define LineSensor_h

#include "Arduino.h"

class LineSensor
{
public:
  LineSensor(unsigned char pin);

  bool isWhite() const;
private:
  unsigned char mPin;

};

#endif

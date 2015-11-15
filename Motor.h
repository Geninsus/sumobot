#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
public:
	Motor(unsigned char input1, unsigned char input2, unsigned char enable);

	void setValue(unsigned char value);
	void setDirection(bool direction);

	unsigned char getValue() const {return mValue;}
	bool getDirection() const {return mDirection;}

private:
	unsigned char mInput1;
	unsigned char mInput2;
	unsigned char mEnable;

	unsigned char mValue;
	bool mDirection;
};

#endif

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

enum rotationDirection {forward = 0, backward = 1};

class Motor
{
public:
	Motor(unsigned char input1, unsigned char input2, unsigned char enable);

	void setPower(const unsigned char& power);
	void setDirection(const rotationDirection& d);

	unsigned char getPower() const {return mPower;}
	bool getDirection() const {return mDirection;}

private:
	unsigned char mInput1;
	unsigned char mInput2;
	unsigned char mEnable;

	unsigned char mPower;
	bool mDirection;
};

#endif

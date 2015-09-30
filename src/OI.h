#ifndef OI_H
#define OI_H
#include <RobotMap.h>
#include "WPILib.h"

class OI {
private:
	Joystick *leftStick, *rightStick;
public:
	OI();
	double getLeftStickY();
	double getRightStickY();
};

#endif

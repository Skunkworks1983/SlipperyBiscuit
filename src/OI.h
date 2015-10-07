#ifndef OI_H
#define OI_H
#include <RobotMap.h>
#include "WPILib.h"

class OI {
private:
	Joystick *leftStick, *rightStick;
	JoystickButton *engageOmniWheelsOn, *engageOmniWheelsOff;
	JoystickButton *toggleFrontLeft,
			*toggleFrontRight, *toggleBackLeft, *toggleBackRight, *toggleAll;
	JoystickButton *shiftUp, *shiftDown;
	JoystickButton *holdEngage;

	void registerListeners();
public:
	OI();
	~OI();
	double getLeftStickY();
	double getRightStickY();
};

#endif

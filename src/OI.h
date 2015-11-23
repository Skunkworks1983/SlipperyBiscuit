#ifndef OI_H
#define OI_H
#include <RobotMap.h>
#include "WPILib.h"

class OI {
private:
	Joystick *leftStick, *rightStick;
	JoystickButton *engageOmniWheelsOn, *engageOmniWheelsOff;
	JoystickButton *toggleFront, *toggleBack, *toggleAll;
	JoystickButton *shiftUp, *shiftDown;
	JoystickButton *holdEngage;

	void registerListeners();
public:
	OI();
	~OI();
	double getLeftStickY();
	double getRightStickY();
	double getRightStickX();
	double getLeftStickX();

};

#endif

#include <Joystick.h>
#include <OI.h>

OI::OI()
{
	leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
	rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);
	// Process operator interface input here.
}

double OI::getLeftStickY(){
	return leftStick->GetY();
}

double OI::getRightStickY(){
	return rightStick->GetY();
}

#include <Buttons/JoystickButton.h>
#include <Commands/EngageOmniWheels.h>
#include <Commands/ToggleOmniWheels.h>
#include <Commands/ShiftDriveBase.h>
#include <Joystick.h>
#include <OI.h>
#include <cstring>

OI::OI() {
	leftStick = new Joystick(OI_JOYSTICK_LEFT_PORT);
	rightStick = new Joystick(OI_JOYSTICK_RIGHT_PORT);

	holdEngage = new JoystickButton(leftStick, 1);

	engageOmniWheelsOff = new JoystickButton(leftStick, 2);
	engageOmniWheelsOn = new JoystickButton(leftStick, 3);

	toggleFront = new JoystickButton(rightStick, 1);
	toggleFront = new JoystickButton(rightStick, 2);

	toggleAll = new JoystickButton(rightStick, 3);

	shiftUp = new JoystickButton(leftStick, 4);
	shiftDown = new JoystickButton(leftStick, 5);

	registerListeners();
}

OI::~OI() {
	delete leftStick;
	delete rightStick;

	delete engageOmniWheelsOn;
	delete engageOmniWheelsOff;

	delete toggleFront;
	delete toggleBack;

	delete toggleAll;
	delete holdEngage;
}

void OI::registerListeners() {
	holdEngage->WhenPressed(new EngageOmniWheels(true));
	holdEngage->WhenReleased(new EngageOmniWheels(false));

	engageOmniWheelsOff->WhenPressed(new EngageOmniWheels(false));
	engageOmniWheelsOn->WhenPressed(new EngageOmniWheels(true));

	toggleFront->WhenPressed(new ToggleOmniWheels(true, false));
	toggleFront->WhenPressed(new ToggleOmniWheels(false, true));

	shiftUp->WhenPressed(new ShiftDrivebase(true));
	shiftDown->WhenPressed(new ShiftDrivebase(false));

	toggleAll->WhenPressed(new ToggleOmniWheels());
}

double OI::getLeftStickY() {
	return leftStick->GetY()*fabs(leftStick->GetY());
}

double OI::getRightStickY() {
	return rightStick->GetY()*fabs(rightStick->GetY());
}

double OI::getRightStickX(){
	return rightStick->GetX()*fabs(rightStick->GetX());
}

double OI::getLeftStickX(){
	return leftStick->GetX()*fabs(leftStick->GetX());
}


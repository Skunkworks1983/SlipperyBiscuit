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

	holdEngage = new JoystickButton(leftStick, 0);

	engageOmniWheelsOff = new JoystickButton(leftStick, 1);
	engageOmniWheelsOn = new JoystickButton(leftStick, 2);

	toggleFrontLeft = new JoystickButton(rightStick, 0);
	toggleFrontRight = new JoystickButton(rightStick, 1);
	toggleBackLeft = new JoystickButton(rightStick, 2);
	toggleBackRight = new JoystickButton(rightStick, 3);

	toggleAll = new JoystickButton(leftStick, 3);

	shiftUp = new JoystickButton(leftStick, 3);
	shiftDown = new JoystickButton(leftStick, 4);

	registerListeners();
}

OI::~OI() {
	delete leftStick;
	delete rightStick;

	delete engageOmniWheelsOn;
	delete engageOmniWheelsOff;

	delete toggleFrontLeft;
	delete toggleFrontRight;
	delete toggleBackLeft;
	delete toggleBackRight;

	delete toggleAll;
	delete holdEngage;
}

void OI::registerListeners() {
	holdEngage->WhenPressed(new EngageOmniWheels(true));
	holdEngage->WhenReleased(new EngageOmniWheels(false));

	engageOmniWheelsOff->WhenPressed(new EngageOmniWheels(false));
	engageOmniWheelsOn->WhenPressed(new EngageOmniWheels(true));

	toggleFrontLeft->WhenPressed(new ToggleOmniWheels(FRONT_LEFT_OMNI_ID));
	toggleFrontRight->WhenPressed(new ToggleOmniWheels(FRONT_RIGHT_OMNI_ID));
	toggleBackLeft->WhenPressed(new ToggleOmniWheels(BACK_LEFT_OMNI_ID));
	toggleBackRight->WhenPressed(new ToggleOmniWheels(BACK_RIGHT_OMNI_ID));

	shiftUp->WhenPressed(new ShiftDrivebase(true));
	shiftDown->WhenPressed(new ShiftDrivebase(false));

	toggleAll->WhenPressed(new ToggleOmniWheels());
}

double OI::getLeftStickY() {
	return leftStick->GetY();
}

double OI::getRightStickY() {
	return rightStick->GetY();
}

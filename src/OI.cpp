#include <Buttons/JoystickButton.h>
#include <Commands/EngageOmniWheels.h>
#include <Commands/ToggleOmniWheels.h>
#include <Joystick.h>
#include <OI.h>

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

	int *a = new int[4];
	memset(a, -1, 4);
	toggleAll->WhenPressed(new ToggleOmniWheels(a)); //TODO: fix(using ToggleOmniWheels() with no argument gives an "is ambiguous" error)
}

double OI::getLeftStickY() {
	return leftStick->GetY();
}

double OI::getRightStickY() {
	return rightStick->GetY();
}

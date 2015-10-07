/*
 * ToggleOmniWheels.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: s-4020395
 */

#include <CommandBase.h>
#include <Commands/ToggleOmniWheels.h>
#include <Subsystems/DriveBase.h>

ToggleOmniWheels::ToggleOmniWheels(bool front_left, bool front_right,
		bool back_left, bool back_right) {
	Requires(CommandBase::drivebase);
	this->front_left = front_left;
	this->front_right = front_right;
	this->back_left = back_left;
	this->back_right = back_right;

}

ToggleOmniWheels::ToggleOmniWheels(int id) {
	Requires(CommandBase::drivebase);
	switch (id) {
	case FRONT_LEFT_OMNI_ID:
		front_left = true;
		break;
	case FRONT_RIGHT_OMNI_ID:
		front_right = true;
		break;
	case BACK_LEFT_OMNI_ID:
		back_left = true;
		break;
	case BACK_RIGHT_OMNI_ID:
		back_right = true;
		break;
	}
}

ToggleOmniWheels::ToggleOmniWheels() {
	Requires(CommandBase::drivebase);
	front_left = true;
	front_right = true;
	back_left = true;
	back_right = true;
}

ToggleOmniWheels::~ToggleOmniWheels() {

}

void ToggleOmniWheels::Initialize() {
	DriveBase *d = CommandBase::drivebase;
	if (front_left) {
		d->toggleSolenoid(FRONT_LEFT_OMNI_ID);
	}
	if (front_right) {
		d->toggleSolenoid(FRONT_RIGHT_OMNI_ID);
	}
	if (back_left) {
		d->toggleSolenoid(BACK_LEFT_OMNI_ID);
	}
	if (back_right) {
		d->toggleSolenoid(BACK_RIGHT_OMNI_ID);
	}
}

void ToggleOmniWheels::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleOmniWheels::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ToggleOmniWheels::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleOmniWheels::Interrupted() {
	End();
}

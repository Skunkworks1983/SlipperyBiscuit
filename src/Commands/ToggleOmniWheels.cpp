/*
 * ToggleOmniWheels.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: s-4020395
 */

#include <CommandBase.h>
#include <Commands/ToggleOmniWheels.h>
#include <Subsystems/DriveBase.h>

ToggleOmniWheels::ToggleOmniWheels(bool front, bool back) {
	Requires(CommandBase::drivebase);
	this->front = front;
	this->back = back;
}

ToggleOmniWheels::ToggleOmniWheels() {
	Requires(CommandBase::drivebase);
	front = true;
	back = true;
}

ToggleOmniWheels::~ToggleOmniWheels() {

}

void ToggleOmniWheels::Initialize() {
	DriveBase *d = CommandBase::drivebase;
	if (front) {
		d->toggleSolenoid(FRONT_OMNI_ID);
	}
	if (back) {
		d->toggleSolenoid(BACK_OMNI_ID);
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

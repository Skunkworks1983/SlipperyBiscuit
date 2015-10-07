/*
 * EngageOmniWheels.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: s-4020395
 */

#include <CommandBase.h>
#include <Commands/EngageOmniWheels.h>
#include <Subsystems/DriveBase.h>

EngageOmniWheels::EngageOmniWheels(bool front_left, bool front_right,
		bool back_left, bool back_right) {
	Requires(CommandBase::drivebase);
	this->front_left = front_left;
	this->front_right = front_right;
	this->back_left = back_left;
	this->back_right = back_right;
}

EngageOmniWheels::EngageOmniWheels(bool on) {
	Requires(CommandBase::drivebase);
	front_left = on;
	front_right = on;
	back_left = on;
	back_right = on;
}

EngageOmniWheels::~EngageOmniWheels() {

}

void EngageOmniWheels::Initialize() {
	DriveBase *d = CommandBase::drivebase;
	d->engageSolenoid(FRONT_LEFT_OMNI_ID, front_left);
	d->engageSolenoid(FRONT_RIGHT_OMNI_ID, front_right);
	d->engageSolenoid(BACK_LEFT_OMNI_ID, back_left);
	d->engageSolenoid(BACK_RIGHT_OMNI_ID, back_right);
}

void EngageOmniWheels::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool EngageOmniWheels::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void EngageOmniWheels::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EngageOmniWheels::Interrupted() {
	End();
}

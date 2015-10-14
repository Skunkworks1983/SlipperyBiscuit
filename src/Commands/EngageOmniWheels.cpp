/*
 * EngageOmniWheels.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: s-4020395
 */

#include <CommandBase.h>
#include <Commands/EngageOmniWheels.h>
#include <Subsystems/DriveBase.h>

EngageOmniWheels::EngageOmniWheels(bool front, bool back) {
	Requires(CommandBase::drivebase);
	this->front = front;
	this->back = back;
}

EngageOmniWheels::EngageOmniWheels(bool on) {
	Requires(CommandBase::drivebase);
	back = on;
	front = on;
}

EngageOmniWheels::~EngageOmniWheels() {

}

void EngageOmniWheels::Initialize() {
	DriveBase *d = CommandBase::drivebase;
	d->engageSolenoid(FRONT_OMNI_ID, front);
	d->engageSolenoid(BACK_OMNI_ID, back);
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

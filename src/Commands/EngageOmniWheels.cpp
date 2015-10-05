/*
 * EngageOmniWheels.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: s-4020395
 */

#include <CommandBase.h>
#include <Commands/EngageOmniWheels.h>
#include <Subsystems/DriveBase.h>

EngageOmniWheels::EngageOmniWheels(int ids[DRIVEBASE_NUMBER_OMNI], bool on) {
	Requires(CommandBase::drivebase);
	this->on = on;
	memcpy(ids, this->ids, sizeof(this->ids));
}

EngageOmniWheels::EngageOmniWheels(int id, bool on) {
	Requires(CommandBase::drivebase);
	this->on = on;
	memset(this->ids, -1, DRIVEBASE_NUMBER_OMNI);// so that id 0 isn't called multiple times (should only affect toggle)
	ids[0] = id;
}

EngageOmniWheels::EngageOmniWheels(bool on) {
	Requires(CommandBase::drivebase);
	this->on = on;
	memset(this->ids, -1, DRIVEBASE_NUMBER_OMNI);
}

EngageOmniWheels::~EngageOmniWheels() {

}

void EngageOmniWheels::Initialize() {
	bool none_specified = true;
	for (int i = 0; i < DRIVEBASE_NUMBER_OMNI; i++) {
		if (ids[i] != -1) {
			CommandBase::drivebase->engageSolenoids(this->on);
			none_specified = false;
		}
	}
	if (none_specified) {
		CommandBase::drivebase->engageSolenoids(this->on);
	}
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

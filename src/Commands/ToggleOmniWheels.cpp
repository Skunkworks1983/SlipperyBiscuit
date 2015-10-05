/*
 * ToggleOmniWheels.cpp
 *
 *  Created on: Oct 4, 2015
 *      Author: s-4020395
 */

#include <Commands/ToggleOmniWheels.h>
#include <CommandBase.h>
#include <Subsystems/DriveBase.h>

ToggleOmniWheels::ToggleOmniWheels(int ids[DRIVEBASE_NUMBER_OMNI]){
	Requires(CommandBase::drivebase);
	memcpy(ids, this->ids, sizeof(this->ids));
}

ToggleOmniWheels::ToggleOmniWheels(int id) {
	Requires(CommandBase::drivebase);
	memset(this->ids, -1, DRIVEBASE_NUMBER_OMNI);// so that id 0 isn't called multiple times (should only affect toggle)
	ids[0] = id;
}

ToggleOmniWheels::ToggleOmniWheels(){
	Requires(CommandBase::drivebase);
	memset(this->ids, -1, DRIVEBASE_NUMBER_OMNI);
}

ToggleOmniWheels::~ToggleOmniWheels() {

}

void ToggleOmniWheels::Initialize() {
	bool none_specified = true;
	for (int i = 0; i < DRIVEBASE_NUMBER_OMNI; i++) {
		if (ids[i] != -1) {
			CommandBase::drivebase->toggleSolenoid(ids[i]);
			none_specified = false;
		}
	}
	if (none_specified) {
		CommandBase::drivebase->toggleSolenoids();
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

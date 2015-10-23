/*
 * EngageOmniWheels.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: s-4020395
 */

#include <Commands/Command.h>
#include <Commands/DriveDistance.h>

DriveDistance::DriveDistance(float _distance, float _speed) {
	Requires(drivebase);
	this->distance = _distance;
	this->speed = _speed;
}

DriveDistance::~DriveDistance() {

}

void DriveDistance::Initialize() {
	drivebase->resetEncoders();
	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(speed);
}

void DriveDistance::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool DriveDistance::IsFinished() {
	return drivebase->getLeftDistance() >= distance
			&& drivebase->getRightDistance() >= distance;
}

// Called once after isFinished returns true
void DriveDistance::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveDistance::Interrupted() {
	End();
}

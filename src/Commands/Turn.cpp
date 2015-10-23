/*
 * EngageOmniWheels.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: s-4020395
 */


#include <Commands/Command.h>
#include <Commands/Turn.h>


Turn::Turn(float _distance, float _speed) {
this->distance = _distance;
this->speed = _speed;
}

Turn::~Turn() {

}

void Turn::Initialize() {
	drivebase->resetEncoders();
	drivebase->setLeftSpeed(speed * 0.5);
	drivebase->setRightSpeed(speed);
}

void Turn::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool Turn::IsFinished() {
	return drivebase->getLeftDistance() >= distance
			&& drivebase->getRightDistance() >= distance * 0.5;
}

// Called once after isFinished returns true
void Turn::End() {
drivebase->setLeftSpeed(0);
drivebase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {
	End();
}

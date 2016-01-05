/*
 * Drive DistAnce.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Tucker
 */

#include <CommandBase.h>
#include <Commands/DriveDistance.h>

DriveDistance::DriveDistance(float distance, float speed) {
	Requires (drivebase);
	this->distance = distance;
	this->speed = speed;

}

DriveDistance::~DriveDistance() {

}

void DriveDistance::Initialize() {
	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(speed);
	drivebase->resetEncoders();
}

void DriveDistance::Execute() {

}

void DriveDistance::Interrupted() {
	End();
}

void DriveDistance::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);

}

bool DriveDistance::IsFinished() {

	return //drivebase->getLeftDistance() >= distance;
		 drivebase->getRightDistance() >= distance;
}


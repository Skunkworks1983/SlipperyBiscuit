/*
 * DriveRight.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Tucker
 */


#include <CommandBase.h>
#include <Commands/DriveRight.h>

DriveRight::DriveRight(float distance, float speed) {
	Requires (drivebase);
	this->distance = distance;
	this->speed = speed;

}

DriveRight::~DriveRight() {

}

void DriveRight::Initialize() {
	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(-speed);
	drivebase->resetEncoders();
}

void DriveRight::Execute() {

}

void DriveRight::Interrupted() {
	End();
}

void DriveRight::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);

}

bool DriveRight::IsFinished() {

	return drivebase->getLeftDistance() >= distance
			&& drivebase->getRightDistance() >= distance;
}





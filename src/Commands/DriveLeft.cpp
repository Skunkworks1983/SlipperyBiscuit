/*
 * DriveLeft.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Tucker
 */

#include <CommandBase.h>
#include <Commands/DriveLeft.h>

DriveLeft::DriveLeft(float distance, float speed) {
	Requires (drivebase);
	this->distance = distance;
	this->speed = speed;

}

DriveLeft::~DriveLeft() {

}

void DriveLeft::Initialize() {
	drivebase->setLeftSpeed(-speed);
	drivebase->setRightSpeed(speed);
	drivebase->resetEncoders();
}

void DriveLeft::Execute() {

}

void DriveLeft::Interrupted() {
	End();
}

void DriveLeft::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setLeftSpeed(0);

}

bool DriveLeft::IsFinished() {

	return drivebase->getLeftDistance() >= distance
			&& drivebase->getRightDistance() >= distance;
}








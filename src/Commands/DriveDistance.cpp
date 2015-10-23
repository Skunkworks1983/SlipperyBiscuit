/*
 * DriveDistance.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: aviatorailis
 */
#include <CommandBase.h>
#include <Commands/DriveDistance.h>

DriveDistance::DriveDistance(float distance, float speed) {
	this->distance = distance;
	this->speed = speed;
}

DriveDistance::~DriveDistance() {

}

void DriveDistance::Initialize() {

}

void DriveDistance::Execute() {

}

void DriveDistance::Interrupted() {
	End();
}

void DriveDistance::End() {

}

bool DriveDistance::IsFinished() {
	return false;
}




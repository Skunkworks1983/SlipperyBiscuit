#include <Commands/DriveDistance.h>

DriveDistance::DriveDistance(float _distance, float _speed) {
	Requires(drivebase);
	distance = _distance;
	speed = _speed;
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

void DriveDistance::Interrupted() {
	End();
}

void DriveDistance::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}

bool DriveDistance::IsFinished() {
	return drivebase->getLeftDistance() >= distance
			&& drivebase->getRightDistance() >= distance;
}

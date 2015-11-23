#include "MoveForward.h"

MoveForward::MoveForward(double inches, double speed) {
	Requires(CommandBase::drivebase);
	this->inches = inches;
	this->speed = speed;
}
void MoveForward::Initialize() {
	drivebase->setLeftSpeed(speed);
	drivebase->setRightSpeed(speed);
}
void MoveForward::Execute() {
}
bool MoveForward::IsFinished() {
	return (inches > 0 ?
			drivebase->getLeftEncoderRotation() >= inches :
			drivebase->getLeftEncoderRotation() <= inches);
}
void MoveForward::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}
void MoveForward::Interrupted() {
	End();
}

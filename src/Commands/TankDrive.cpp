#include <Commands/TankDrive.h>
#include <Subsystems/DriveBase.h>

TankDrive::TankDrive() {
	Requires(CommandBase::drivebase);
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
	drivebase->setLeftSpeed(oi->getLeftStickY());
	drivebase->setRightSpeed(oi->getRightStickY());
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TankDrive::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {
	End();
}

#include <Commands/ArcadeDrive.h>
#include <Subsystems/DriveBase.h>

ArcadeDrive::ArcadeDrive() {
	Requires(CommandBase::drivebase);
}

// Called just before this Command runs the first time
void ArcadeDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArcadeDrive::Execute() {
	drivebase->setLeftSpeed(oi->getLeftStickY() + oi->getLeftStickX());
	drivebase->setRightSpeed(oi->getLeftStickY() - oi->getRightStickX());
}

// Make this return true when this Command no longer needs to run execute()
bool ArcadeDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArcadeDrive::End() {
	drivebase->setLeftSpeed(0);
	drivebase->setRightSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArcadeDrive::Interrupted() {
	End();
}

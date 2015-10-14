#include <CommandBase.h>
#include <Commands/ShiftDrivebase.h>
#include <Subsystems/DriveBase.h>

ShiftDrivebase::ShiftDrivebase(bool high) {
	Requires(CommandBase::drivebase);
	this->high = high;
}

ShiftDrivebase::~ShiftDrivebase() {
}

void ShiftDrivebase::Initialize() {
	CommandBase::drivebase->shift(this->high);
}
void ShiftDrivebase::Execute() {

}
bool ShiftDrivebase::IsFinished() {
	return true;
}
void ShiftDrivebase::End() {

}
void ShiftDrivebase::Interrupted() {

}

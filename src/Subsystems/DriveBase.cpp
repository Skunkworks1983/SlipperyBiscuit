#include <CANTalon.h>
#include <Commands/TankDrive.h>
#include <RobotMap.h>
#include <Subsystems/DriveBase.h>

DriveBase::DriveBase() :
		Subsystem("DriveBase") {
	leftMotor1 = new CANTalon(DRIVEBASE_LEFTMOTOR_1_PORT);
	leftMotor2 = new CANTalon(DRIVEBASE_LEFTMOTOR_2_PORT);
	leftMotor3 = new CANTalon(DRIVEBASE_LEFTMOTOR_3_PORT);

	rightMotor1 = new CANTalon(DRIVEBASE_RIGHTMOTOR_1_PORT);
	rightMotor2 = new CANTalon(DRIVEBASE_RIGHTMOTOR_2_PORT);
	rightMotor3 = new CANTalon(DRIVEBASE_RIGHTMOTOR_3_PORT);
}

void DriveBase::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveBase::setLeftSpeed(double speed) {
	leftMotor1->Set(speed);
	leftMotor2->Set(speed);
	leftMotor3->Set(speed);
}

void DriveBase::setRightSpeed(double speed) {
	rightMotor1->Set(speed);
	rightMotor2->Set(speed);
	rightMotor3->Set(speed);
}

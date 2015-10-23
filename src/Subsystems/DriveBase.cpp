#include <Commands/TankDrive.h>
#include <DoubleSolenoid.h>
#include <RobotMap.h>
#include <Solenoid.h>
#include <Subsystems/DriveBase.h>
#include <Talon.h>

DriveBase::DriveBase() :
		Subsystem("DriveBase") {
	leftMotor1 = new Talon(DRIVEBASE_LEFTMOTOR_1_PORT);
	leftMotor2 = new Talon(DRIVEBASE_LEFTMOTOR_2_PORT);
	leftMotor3 = new Talon(DRIVEBASE_LEFTMOTOR_3_PORT);

	rightMotor1 = new Talon(DRIVEBASE_RIGHTMOTOR_1_PORT);
	rightMotor2 = new Talon(DRIVEBASE_RIGHTMOTOR_2_PORT);
	rightMotor3 = new Talon(DRIVEBASE_RIGHTMOTOR_3_PORT);

	frontOmni = new DoubleSolenoid(FRONT_OMNI_PORT);
	backOmni = new DoubleSolenoid(BACK_OMNI_PORT);

	shifterLeft = new Solenoid(SHIFTER_LEFT_PORT);
	shifterRight = new Solenoid(SHIFTER_RIGHT_PORT);

	leftEncoder = new Encoder (DRIVEBASE_LEFT_ENCODER_PORTS);
	rightEncoder = new Encoder (DRIVEBASE_RIGHT_ENCODER_PORTS);
}

DriveBase::~DriveBase() {
	delete leftMotor1;
	delete leftMotor2;
	delete leftMotor3;
	delete rightMotor1;
	delete rightMotor2;
	delete rightMotor3;

	delete frontOmni;
	delete backOmni;
}

void DriveBase::shift(bool high) {
	shifterLeft->Set(high);
	shifterRight->Set(high);
}

void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive());
}

void DriveBase::setLeftSpeed(double speed) {
	leftMotor1->Set(-speed);
	leftMotor2->Set(-speed);
	leftMotor3->Set(-speed);
}

void DriveBase::setRightSpeed(double speed) {
	rightMotor1->Set(speed);
	rightMotor2->Set(speed);
	rightMotor3->Set(speed);
}

void DriveBase::engageSolenoid(int id, bool on) {
	switch (id) {
	case FRONT_OMNI_ID:
		frontOmni->Set(
				on ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
		break;
	case BACK_OMNI_ID:
		backOmni->Set(on ? DoubleSolenoid::kForward : DoubleSolenoid::kReverse);
		break;
	}
}

void DriveBase::toggleSolenoid(int id) {
	switch (id) {
	case FRONT_OMNI_ID:
		frontOmni->Set(
				frontOmni->Get() == DoubleSolenoid::kForward ?
						DoubleSolenoid::kReverse : DoubleSolenoid::kForward);
		break;
	case BACK_OMNI_ID:
		backOmni->Set(backOmni->Get() == DoubleSolenoid::kForward ?
				DoubleSolenoid::kReverse : DoubleSolenoid::kForward);
		break;
	}
}

void DriveBase::engageSolenoids(bool on) {
	engageSolenoid(FRONT_OMNI_ID, on);
	engageSolenoid(BACK_OMNI_ID, on);
}

void DriveBase::toggleSolenoids() {
	toggleSolenoid(FRONT_OMNI_ID);
	toggleSolenoid(BACK_OMNI_ID);
}

float DriveBase::getLeftDistance() {
return leftEncoder->GetDistance();
}

float DriveBase::getRightDistance() {
	return rightEncoder->GetDistance();
}
void DriveBase::resetEncoders(){
	leftEncoder->Reset();
	rightEncoder->Reset();
}

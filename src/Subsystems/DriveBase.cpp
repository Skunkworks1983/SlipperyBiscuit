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

	frontLeftOmni = new Solenoid(FRONT_LEFT_OMNI_PORT);
	frontRightOmni = new Solenoid(FRONT_RIGHT_OMNI_PORT);
	backLeftOmni = new Solenoid(BACK_LEFT_OMNI_PORT);
	backRightOmni = new Solenoid(BACK_RIGHT_OMNI_PORT);
}

DriveBase::~DriveBase(){
	delete leftMotor1;
	delete leftMotor2;
	delete leftMotor3;
	delete rightMotor1;
	delete rightMotor2;
	delete rightMotor3;

	delete frontLeftOmni;
	delete frontRightOmni;
	delete backLeftOmni;
	delete backRightOmni;
}

void DriveBase::InitDefaultCommand() {
	SetDefaultCommand(new TankDrive());
}

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

void DriveBase::engageSolenoid(int id, bool on) {
	switch (id) {
	case FRONT_LEFT_OMNI_ID:
		frontLeftOmni->Set(on);
		break;
	case FRONT_RIGHT_OMNI_ID:
		frontRightOmni->Set(on);
		break;
	case BACK_LEFT_OMNI_ID:
		backLeftOmni->Set(on);
		break;
	case BACK_RIGHT_OMNI_ID:
		backRightOmni->Set(on);
		break;
	}
}

void DriveBase::toggleSolenoid(int id) {
	switch (id) {
	case FRONT_LEFT_OMNI_ID:
		frontLeftOmni->Set(!frontLeftOmni->Get());
		break;
	case FRONT_RIGHT_OMNI_ID:
		frontRightOmni->Set(!frontRightOmni->Get());
		break;
	case BACK_LEFT_OMNI_ID:
		backLeftOmni->Set(!backLeftOmni->Get());
		break;
	case BACK_RIGHT_OMNI_ID:
		backRightOmni->Set(!backRightOmni->Get());
		break;
	}
}

void DriveBase::engageSolenoids(bool on) {
	for (int i = 0; i < DRIVEBASE_NUMBER_OMNI; i++) {
		engageSolenoid(i, on);
	}
}

void DriveBase::toggleSolenoids() {
	for (int i = 0; i < DRIVEBASE_NUMBER_OMNI; i++) {
		toggleSolenoid(i);
	}
}


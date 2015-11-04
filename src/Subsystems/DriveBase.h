#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem {
private:
	Talon *leftMotor1, *leftMotor2, *leftMotor3, *rightMotor1, *rightMotor2,
			*rightMotor3;
	DoubleSolenoid *frontOmni, *backOmni;
	DoubleSolenoid *shifter, *shifterRight;

	Encoder *leftEncoder, *rightEncoder;
public:
	DriveBase();
	~DriveBase();
	void setLeftSpeed(double speed);
	void setRightSpeed(double speed);
	void InitDefaultCommand();
	void toggleSolenoids();
	void engageSolenoids(bool on);
	void toggleSolenoid(int id);
	void engageSolenoid(int id, bool on);
	void shift(bool high);
	float getLeftEncoderRotation();
	float getRightEncoderRotation();

};

#endif

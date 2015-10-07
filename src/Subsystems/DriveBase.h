#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem {
private:
	CANTalon *leftMotor1, *leftMotor2, *leftMotor3, *rightMotor1, *rightMotor2,
			*rightMotor3;
	Solenoid *frontLeftOmni, *frontRightOmni, *backLeftOmni, *backRightOmni;
	Solenoid *shifterLeft, *shifterRight;
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
};

#endif

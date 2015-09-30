#ifndef DRIVEBASE_H
#define DRIVEBASE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveBase: public Subsystem {
private:
	CANTalon *leftMotor1, *leftMotor2, *leftMotor3, *rightMotor1, *rightMotor2,
			*rightMotor3;
public:
	DriveBase();
	void setLeftSpeed(double speed);
	void setRightSpeed(double speed);
	void InitDefaultCommand();
};

#endif

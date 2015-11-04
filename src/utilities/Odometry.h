#include <time.h>
#include "Vector.h"
#include <CommandBase.h>
//#include <cmath>
#include <math.h>

class Odometry{
private:
	float wheel_diameter, axle_length;
	double lastTimeMs, currentTimeMs;
	double lastEncoderLeft, lastEncoderRight;
	Vector *currentVelocity;
	Vector *currentPosition;
	DriveBase *d = CommandBase::drivebase;
public:
	Odometry(float wheel_diameter, float axle_length);
	double getFieldX();
	double getFieldY();
	Vector *getFieldPosition();
	Vector *getCurrentVelocity();
	void update(double _currentTimeMs, double encoderTickLeft, double encoderTickRight);
};
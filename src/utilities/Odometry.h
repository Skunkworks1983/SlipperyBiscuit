#include <time.h>
#include "Vector.h"
#include <CommandBase.h>
#include <math.h>

class Odometry{
private:
	float wheel_diameter, axle_length;
	double lastTimeMs, currentTimeMs;
	double lastEncoderLeft, lastEncoderRight;
	Vector *currentVelocity, *currentPosition;
public:
	Odometry(float wheel_diameter, float axle_length);

	double getFieldX();
	double getFieldY();
	Vector *getFieldPosition();
	Vector *getCurrentVelocity();
	void update(double _currentTimeMs, double encoderTickLeft, double encoderTickRight);
};

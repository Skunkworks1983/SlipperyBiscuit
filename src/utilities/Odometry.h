#include <time.h>
#include "Vector.h"
#include <CommandBase.h>
#include <math.h>

class Odometry{
private:
	NetworkTable *data;
	float wheel_diameter, axle_length;
	double lastTimeMs;
	double lastEncoderLeft, lastEncoderRight;
	Vector *currentVelocity, *currentPosition;
	double lastAngle;
public:
	Odometry(float wheel_diameter, float axle_length);

	double getFieldX();
	double getFieldY();
	Vector *getFieldPosition();
	Vector *getCurrentVelocity();
	void update(double currentTimeMs, double encoderTickLeft, double encoderTickRight);
};

#include <RobotMap.h>
#include <utilities/Odometry.h>

Odometry::Odometry(float wheel_diameter, float axle_length) :
		wheel_diameter(wheel_diameter), axle_length(axle_length) {
	currentPosition = new Vector(0, 0);
	currentVelocity = new Vector(0, 0);
	lastTimeMs = 0;
	lastEncoderLeft = 0;
	lastEncoderRight = 0;
	//NetworkTable::SetServerMode();
	data = NetworkTable::GetTable("odometrydata");
	//data->Initialize();
}

double Odometry::getFieldX() {
	return currentPosition->getCartesianX();
}

double Odometry::getFieldY() {
	return currentPosition->getCartesianY();
}

Vector *Odometry::getFieldPosition() {
	return currentPosition;
}

Vector *Odometry::getCurrentVelocity() {
	return currentVelocity;
}

void Odometry::update(double currentTimeMs, double encoderDistanceLeft,
		double encoderDistanceRight) { //possibly need to pass in current velocity instead of encoderDistance with other modifications

	double dLeft = encoderDistanceLeft - lastEncoderLeft; //could reset encoder instead each time at end, not sure if total encoder ticks are useful ornot
	double dRight = encoderDistanceRight - lastEncoderRight;

	lastEncoderLeft = encoderDistanceLeft;
	lastEncoderRight = encoderDistanceRight;

	double angleLeft = dLeft * wheel_diameter * M_PI;	//divide by circumference to cancel distance unit
	double angleRight = dRight * wheel_diameter * M_PI;

	double dTheta = ((angleLeft - angleRight) / (axle_length));	//get radians by dividing difference of radians by total radians

	lastAngle += dTheta;

	double dTranslation = (dLeft + dRight) / 2;

	if (currentPosition != NULL) {
		Vector *added = new Vector(dTranslation, lastAngle);
		currentPosition->add(added);
		delete added;
	} else {
		currentPosition = new Vector(dTranslation, lastAngle);
	}

	if (currentVelocity != NULL) {
		Vector *added = new Vector(
				(dTranslation * 1000) / (currentTimeMs - lastTimeMs),
				(dTheta * 1000) / (currentTimeMs - lastTimeMs));
		currentVelocity->add(added);
		delete added;
	} else {
		currentVelocity = new Vector(
				(dTranslation * 1000) / (currentTimeMs - lastTimeMs),
				(dTheta * 1000) / (currentTimeMs - lastTimeMs));
	}

	lastTimeMs = currentTimeMs;

	data->PutNumber("X", currentPosition->getCartesianX());
	data->PutNumber("Y", currentPosition->getCartesianY());
	SmartDashboard::PutNumber("LastAngle", lastAngle);
	SmartDashboard::PutNumber("X", currentPosition->getCartesianX());
	SmartDashboard::PutNumber("Y", currentPosition->getCartesianY());
}

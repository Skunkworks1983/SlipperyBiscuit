#include "Odometry.h"

Odometry::Odometry(float wheel_diameter, float axle_length) :
		wheel_diameter(wheel_diameter), axle_length(axle_length) {
	currentPosition = new Vector(0, 0);
	currentVelocity = new Vector(0, 0);
	lastTimeMs = 0;
	currentTimeMs = 1;
	lastEncoderLeft = 0;
	lastEncoderRight = 0;
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

void Odometry::update(double _currentTimeMs, double encoderDistanceLeft,
		double encoderDistanceRight) {	//possibly need to pass in current velocity instead of encoderDistance with other modifications
	this->currentTimeMs = _currentTimeMs;

	double dLeft = encoderDistanceLeft - lastEncoderLeft; //could reset encoder instead each time at end, not sure if total encoder ticks are useful ornot
	double dRight = encoderDistanceRight - lastEncoderRight;

	double angleLeft = dLeft / (wheel_diameter * M_PI);	//divide by circumference to cancel distance unit
	double angleRight = dRight / (wheel_diameter * M_PI);

	double dTheta = ((angleLeft - angleRight) / (axle_length)) / 2;	//get radians by dividing difference of radians by total radians

	double dTranslation = (dLeft + dRight) / 2;

	if (currentVelocity != NULL) {
		currentVelocity->setMagnitude(dTranslation / (currentTimeMs - lastTimeMs));
		currentVelocity->setTheta(dTheta / (currentTimeMs - lastTimeMs));
	} else {
		currentVelocity = new Vector(
				dTranslation / (currentTimeMs - lastTimeMs),
				dTheta / (currentTimeMs - lastTimeMs));
	}

	if (currentPosition != NULL) {
		currentPosition->setMagnitude(
				currentPosition->getMagnitude() + dTranslation);
		currentPosition->setTheta(currentPosition->getTheta() + dTheta);
	} else {
		currentPosition = new Vector(dTranslation, dTheta);
	}
	lastTimeMs = currentTimeMs;
}

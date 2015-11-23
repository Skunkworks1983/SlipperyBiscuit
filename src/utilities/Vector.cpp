#include "Vector.h"

Vector::Vector(double magnitude, double theta) :
		magnitude(magnitude), theta(theta) {

}

double Vector::getMagnitude() {
	return magnitude;
}

double Vector::getTheta() {
	return theta;
}

void Vector::setMagnitude(double magnitude) {
	this->magnitude = magnitude;
}

void Vector::setTheta(double theta) {
	this->theta = theta;
}

void Vector::multiply(Vector *v) {
	double vx, vy;
	//cross product probably
	//this functionality only useful in kalmin filtering etc
}

void Vector::add(Vector *v) {
	double ax = v->getCartesianX();
	double ay = v->getCartesianY();
	double newX = ax + this->getCartesianX();
	double newY = ay + this->getCartesianY();
	double newTheta = 0;
	if (newX != 0) {
		newTheta = atan(newY / newX);
	}
	double newMag = sqrt(pow(newX, 2) + pow(newY, 2));
	this->magnitude = newMag;
	this->theta = newTheta;
}

double Vector::getCartesianY() {
	return magnitude * sin(theta);
}

double Vector::getCartesianX() {
	return magnitude * cos(theta);
}


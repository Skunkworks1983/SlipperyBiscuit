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

void Vector::setMagnitude(double magnitude){
	this->magnitude = magnitude;
}

void Vector::setTheta(double theta){
	this->theta = theta;
}

Vector *Vector::multiply(Vector *v) {
	double vx, vy;
	Vector *out = new Vector(vx, vy);
	return out;
}

Vector *Vector::add(Vector *v) {
	double vx, vy;
	Vector *out = new Vector(vx, vy);
	return out;
}

double Vector::getCartesianY() {
	return magnitude * sin(theta);
}

double Vector::getCartesianX() {
	return magnitude * cos(theta);
}


#include <cmath>

class Vector{
private:
	double magnitude, theta;
public:
	Vector(double magnitude, double theta);

	void setMagnitude(double magnitude);
	void setTheta(double theta);

	double getMagnitude();
	double getTheta();
	double getCartesianY();
	double getCartesianX();
	void multiply(Vector *v);
	void add(Vector *v);
};

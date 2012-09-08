#ifndef INCLUDED_POINT
#define INCLUDED_POINT

class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point(double x, double y, double z);
	Point(const Point &p1);

	Point &operator=(const Point rhs);

	void trace(double incrementValue);

	void setX(double x);
	Point* incrementX(double x);
	double getX();

	void setY(double y);
	Point* incrementY(double y);
	double getY();

	void setZ(double z);
	Point* incrementZ(double z);
	double getZ();
};

#endif

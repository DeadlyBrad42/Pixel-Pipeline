#ifndef INCLUDED_RAY
#define INCLUDED_RAY

class Ray
{
private:
	Point startPoint;
	Point targetPoint;

public:
	Ray(Point start, Point targer);

	Point getStart();
	void setStart(Point start);

	Point getTarget();
	void setTarget(Point target);
};

#endif

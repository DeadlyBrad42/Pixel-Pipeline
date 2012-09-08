#ifndef INCLUDED_CAMERA
#define INCLUDED_CAMERA

class Camera
{
private:
	Point location;
	Point target;

public:
	Camera(Point location, Point target);

	void setLocation(Point location);
	Point getLocation();

	void setTarget(Point target);
	Point getTarget();
};

#endif

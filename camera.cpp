Camera::Camera(Point location = Point(0, 0, 0), Point target = Point(0, 0, 0))
{
	this->location = location;
	this->target = target;
}

void Camera::setLocation(Point location){this->location = location;}
Point Camera::getLocation(){return location;}

void Camera::setTarget(Point target){this->target = target;}
Point Camera::getTarget(){return target;}

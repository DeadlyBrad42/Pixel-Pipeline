Point::Point(double x = 0, double y = 0, double z = 0)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point::Point(const Point &p1)
{
	this->x = p1.x;
	this->y = p1.y;
	this->z = p1.z;
}

void Point::trace(double incrementValue)
{
	x += incrementValue;
	y += incrementValue;
}

Point& Point::operator=(const Point rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	this->z = rhs.z;
	return *this;
}

void Point::setX(double x){this->x = x;}
Point *Point::incrementX(double x) {this->x+=x; return this;}
double Point::getX(){return x;}

void Point::setY(double y){this->y = y;}
Point *Point::incrementY(double y) {this->y+=y; return this;}
double Point::getY(){return y;}

void Point::setZ(double z){this->z = z;}
Point *Point::incrementZ(double z) {this->z+=z; return this;}
double Point::getZ(){return z;}

Ray::Ray(Point start, Point target)
{
	startPoint = start;
	targetPoint = target;
}

Point Ray::getStart(){return startPoint;}
void Ray::setStart(Point start){startPoint = start;}

Point Ray::getTarget(){return targetPoint;}
void Ray::setTarget(Point target){targetPoint = target;}

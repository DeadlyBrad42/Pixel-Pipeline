Cube::Cube(bool show, char red, char green, char blue)
{
	this->show = show;
	this->color.setRed(red);
	this->color.setGreen(green);
	this->color.setBlue(blue);
}

Cube::Cube(bool show, Color color)
{
	this->show = show;
	this->setRed(color.getRed());
	this->setGreen(color.getGreen());
	this->setBlue(color.getBlue());
}

void Cube::setShow(bool show){this->show = show;}
bool Cube::getShow(){return show;}

void Cube::setRed(char red){this->color.setRed(red);}
char Cube::getRed(){return color.getRed();}

void Cube::setBlue(char blue){this->color.setBlue(blue);}
char Cube::getBlue(){return color.getBlue();}

void Cube::setGreen(char green){this->color.setGreen(green);}
char Cube::getGreen(){return color.getGreen();}

void Cube::setColor(Color color){this->color = color;}
Color Cube::getColor(){return color;}

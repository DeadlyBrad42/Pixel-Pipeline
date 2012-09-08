Color::Color(char red, char green, char blue)
{
	this->red = red;
	this->blue = blue;
	this->green = green;
}

char Color::getRed(){return red;}
void Color::setRed(char red){this->red = red;}

char Color::getGreen(){return green;}
void Color::setGreen(char green){this->green = green;}

char Color::getBlue(){return blue;}
void Color::setBlue(char blue){this->blue = blue;}

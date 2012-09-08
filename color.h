#ifndef INCLUDED_COLOR
#define INCLUDED_COLOR

class Color
{
private:
	char red;
	char green;
	char blue;

public:
	Color(char red = 0, char green = 0, char blue = 0);

	char getRed();
	void setRed(char red);

	char getGreen();
	void setGreen(char green);

	char getBlue();
	void setBlue(char blue);
};

#endif

#ifndef INCLUDED_CUBE
#define INCLUDED_CUBE

class Cube
{
private:
	bool show;
	Color color;

public:
	Cube(bool show = false, char red = 0, char green = 0, char blue = 0);
	Cube(bool show, Color color);

	void setShow(bool show);
	bool getShow();

	void setRed(char red);
	char getRed();

	void setBlue(char blue);
	char getBlue();

	void setGreen(char green);
	char getGreen();

	void setColor(Color color);
	Color getColor();
};

#endif

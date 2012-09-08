#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// Other classes
#include "point.h"
#include "point.cpp"
#include "ray.h"
#include "ray.cpp"
#include "camera.h"
#include "camera.cpp"
#include "color.h"
#include "color.cpp"
#include "cube.h"
#include "cube.cpp"

using namespace std;

bool writeBMP(int width, int height, char filename[]);
Color traceRay(Ray aRay);
void initScene(int testNumber);

bool debug = false;
bool debug_lvl2 = false;

const int SCENE_WIDTH = 10;		// scene's x value
const int SCENE_DEPTH = 10;		// scene's y value
const int SCENE_HEIGHT = 10;	// scene's z value
Cube scene[SCENE_WIDTH][SCENE_HEIGHT][SCENE_DEPTH];
//Camera cam = Camera(Point(4.5, 2, 0), Point(4.5, 2, 5));
//Camera cam = Camera(Point(5, 4, 0), Point(5, 4, 9));
Camera cam = Camera(Point(4.5, 2.5, 0), Point(4.5, 2.5, 300));

/*

    Y
    |    Z
    |   /___________
    |  /__/__/__/__/  floor
    | /__/__/__/__/
    |/__/__/__/__/
    |__/__/__/__/__ X
(0,0,0)

(x, y, z)
*/

int main(void)
{
	cout <<"Initilizing scene...\n";
	initScene(3);

	if(debug)
	{
		// output all blocks from the floor to the ceiling
		for(int yCount = 0; yCount < SCENE_HEIGHT; yCount++)
		{
			cout <<"y = " <<yCount <<"\n";
			for(int zCount = 0; zCount < SCENE_DEPTH; zCount++)
			{
				for(int xCount = 0; xCount < SCENE_WIDTH; xCount++)
				{
					if(scene[xCount][yCount][zCount].getShow()) cout <<"1";
					else cout <<"0";
					cout <<" ";
				}
				cout <<"\n";
			}
			cout <<"\n";
		}
	}
	
	cout <<"Reticulating Splines...\n";
	
	if(writeBMP(500, 500, "output.bmp"))
		cout <<"Done.\n";
	else cout <<"Error writing bitmap file.\n";

	return 0;
}

void initScene(int testNumber)
{
	// set everything to be invisible
	for(int xCount = 0; xCount < SCENE_WIDTH; xCount++)
		for(int yCount = 0; yCount < SCENE_HEIGHT; yCount++)
			for(int zCount = 0; zCount < SCENE_DEPTH; zCount++)
				scene[xCount][yCount][zCount].setShow(false);

	if(testNumber == 0)
	{
		/////////// Test Configuration # 0 ////////////////////

		char rArray[] = {255,	240,	89,		107,	240};
		char gArray[] = {0,		237,	236,	117,	121};
		char bArray[] = {0,		0,		78,		214,	1};

		for(int level = 0; level < 5; level++)
		{
			for(int xPos = (0 + level); xPos < (10 - level); xPos++)
			{
				for(int zPos = (0 + level); zPos < (10 - level); zPos++)
				{
					scene[xPos][level][zPos].setRed(rArray[level]);
					scene[xPos][level][zPos].setGreen(gArray[level]);
					scene[xPos][level][zPos].setBlue(bArray[level]);
					scene[xPos][level][zPos].setShow(true);
				}
			}
		}
	}
	else if(testNumber == 1)
	{
		/////////// Test Configuration # 1 ////////////////////

		scene[5][0][9].setRed(255);
		scene[5][0][9].setShow(true);
	}
	else if(testNumber == 2)
	{
		/////////// Test Configuration # 2 ////////////////////
	
		for(int yPos = 0; yPos < 10; yPos++)
		{
			for(int xPos = 0; xPos < 10; xPos++)
			{
				if(yPos % 2 == 0)
				{
					if(xPos % 2 == 0)
					{
						scene[xPos][yPos][9].setRed(255);
						scene[xPos][yPos][9].setGreen(255);
						scene[xPos][yPos][9].setBlue(255);
						scene[xPos][yPos][9].setShow(false);
					}else{
						scene[xPos][yPos][9].setRed(0);
						scene[xPos][yPos][9].setGreen(0);
						scene[xPos][yPos][9].setBlue(0);
						scene[xPos][yPos][9].setShow(true);
					}
				}
				else
				{
					if(xPos % 2 == 1)
					{
						scene[xPos][yPos][9].setRed(255);
						scene[xPos][yPos][9].setGreen(255);
						scene[xPos][yPos][9].setBlue(255);
						scene[xPos][yPos][9].setShow(false);
					}else{
						scene[xPos][yPos][9].setRed(0);
						scene[xPos][yPos][9].setGreen(0);
						scene[xPos][yPos][9].setBlue(0);
						scene[xPos][yPos][9].setShow(true);
					}
				}
			}
		}
		scene[0][0][5].setGreen(255);
		scene[0][0][5].setBlue(0);
		scene[0][0][5].setRed(0);
		scene[0][0][5].setShow(true);
		
		scene[0][0][0].setGreen(0);
		scene[0][0][0].setBlue(0);
		scene[0][0][0].setRed(255);
		scene[0][0][0].setShow(true);
		
		scene[9][9][9].setGreen(0);
		scene[9][9][9].setBlue(255);
		scene[9][9][9].setRed(0);
		scene[9][9][9].setShow(true);
	}
	else if(testNumber == 3)
	{
		/////////// Test Configuration # 2 ////////////////////
		for(int zPos = 0; zPos < 10; zPos++)
		{
			for(int xPos = 0; xPos < 10; xPos++)
			{
				if(zPos % 2 == 0)
				{
					if(xPos % 2 == 0)
					{
						scene[xPos][0][zPos].setRed(255);
						scene[xPos][0][zPos].setGreen(255);
						scene[xPos][0][zPos].setBlue(255);
						scene[xPos][0][zPos].setShow(true);
					}else{
						scene[xPos][0][zPos].setRed(0);
						scene[xPos][0][zPos].setGreen(0);
						scene[xPos][0][zPos].setBlue(0);
						scene[xPos][0][zPos].setShow(true);
					}
				}
				else
				{
					if(xPos % 2 == 1)
					{
						scene[xPos][0][zPos].setRed(255);
						scene[xPos][0][zPos].setGreen(255);
						scene[xPos][0][zPos].setBlue(255);
						scene[xPos][0][zPos].setShow(true);
					}else{
						scene[xPos][0][zPos].setRed(0);
						scene[xPos][0][zPos].setGreen(0);
						scene[xPos][0][zPos].setBlue(0);
						scene[xPos][0][zPos].setShow(true);
					}
				}
			}
		}
		scene[2][1][7].setGreen(255);
		scene[2][1][7].setBlue(0);
		scene[2][1][7].setRed(0);
		scene[2][1][7].setShow(true);
		
		scene[5][1][2].setGreen(0);
		scene[5][1][2].setBlue(255);
		scene[5][1][2].setRed(0);
		scene[5][1][2].setShow(true);
		
		scene[9][1][9].setGreen(255);
		scene[9][1][9].setBlue(255);
		scene[9][1][9].setRed(0);
		scene[9][1][9].setShow(true);
		
		scene[8][1][9].setGreen(255);
		scene[8][1][9].setBlue(255);
		scene[8][1][9].setRed(0);
		scene[8][1][9].setShow(true);
		
		scene[9][1][8].setGreen(255);
		scene[9][1][8].setBlue(255);
		scene[9][1][8].setRed(0);
		scene[9][1][8].setShow(true);
		
		scene[8][1][8].setGreen(255);
		scene[8][1][8].setBlue(255);
		scene[8][1][8].setRed(0);
		scene[8][1][8].setShow(true);
		
		scene[9][2][9].setGreen(0);
		scene[9][2][9].setBlue(0);
		scene[9][2][9].setRed(255);
		scene[9][2][9].setShow(true);
		
		scene[1][1][4].setGreen(255);
		scene[1][1][4].setBlue(0);
		scene[1][1][4].setRed(255);
		scene[1][1][4].setShow(true);
	}

	return;
}

bool writeBMP(int width, int height, char filename[])
{
	ofstream fout;
	fout.open(filename);

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
    unsigned char bmppad[3] = {0,0,0};
    int filesize = 54 + 3*width*height;

    bmpfileheader[ 2] = (char)(filesize);
    bmpfileheader[ 3] = (char)(filesize>> 8);
    bmpfileheader[ 4] = (char)(filesize>>16);
    bmpfileheader[ 5] = (char)(filesize>>24);

    bmpinfoheader[ 4] = (char)(width);
    bmpinfoheader[ 5] = (char)(width>>8);
    bmpinfoheader[ 6] = (char)(width>>16);
    bmpinfoheader[ 7] = (char)(width>>24);
    bmpinfoheader[ 8] = (char)(height);
    bmpinfoheader[ 9] = (char)(height>>8);
    bmpinfoheader[10] = (char)(height>>16);
    bmpinfoheader[11] = (char)(height>>24);

    //write file Header and info header
    for(int fileHeaderCount = 0; fileHeaderCount < 14; fileHeaderCount++) fout <<bmpfileheader[fileHeaderCount];
	for(int infoHeaderCount = 0; infoHeaderCount < 40; infoHeaderCount++) fout <<bmpinfoheader[infoHeaderCount];

	// set Ray's target to point in upper left
	Point target = cam.getTarget();

	// start in lower right, go to upper left (bmp draws upside down)

	double xStart = target.getX() + (width / 2.0);
	double xEnd = target.getX() - (width / 2.0);
	target.setX(xEnd);

	double yStart = target.getY() - (height / 2.0);
	double yEnd = target.getY() + (height / 2.0);
	target.setY(yStart);


	if(debug_lvl2) cout <<"target starts at (" <<target.getX() <<", " <<target.getY() <<", " <<target.getZ() <<")" <<endl;

	Ray toTrace = Ray(cam.getLocation(), target);

	// loop through all possible targets, return & write color
	for(int yCount = 0; yCount < height; yCount++)
	{
		for(int xCount = 0; xCount < width; xCount++)
		{
			if(debug_lvl2) cout <<"Shooting a ray at (" <<toTrace.getTarget().getX() <<", " <<toTrace.getTarget().getY() <<", " <<toTrace.getTarget().getZ() <<")\n";

			// FIRE A RAY
			Color pixel = traceRay(toTrace);
						
			// write resulting color to file
			fout <<pixel.getBlue() <<pixel.getGreen() <<pixel.getRed();
			
			// add 1 to X
			toTrace.setTarget(*(toTrace.getTarget().incrementX(1)));
			target.setX(target.getX() + 1);

		}

		// reset target's x to beginning of line, add 1 to y
		target.setX(xEnd);
		target.setY(target.getY() + 1);
		toTrace = Ray(cam.getLocation(), target);
		
		//number of bytes in a row has to be a multiple of 4. if width is 10, 10/4 has % of 2.
		//so, two zero bytes need to be padded on end of row
		// ie,  10 mod 4  = 2 (zeroes should be padded two times)
		//fout <<(char)00 <<(char)00;
		for(int count = 0; count < (width % 4); count++) fout <<(char)00;
	}
	
	if(debug) cout <<"target finishes at (" <<target.getX() <<", " <<target.getY() <<", " <<target.getZ() <<")" <<endl;

	fout.close();
	return true;
}

Color traceRay(Ray aRay)
{
	//follow a ray until the space you are in is occupied by a cube (return cube's color), or until out of bounds (return magic pink)

	// startpoint = ray.origin
	// while(you are in array)
		// startpoint.incrementALL(towards ray.endpoint)
		// if(you hit one)
			// return thatcube.getColor()

	Point currentPoint = aRay.getStart();

	double divisor = abs(aRay.getTarget().getZ() - aRay.getStart().getZ());
	if(divisor == 0) divisor = 1;
	double dX = (aRay.getTarget().getX() - aRay.getStart().getX()) / divisor;
	double dY = (aRay.getTarget().getY() - aRay.getStart().getY()) / divisor;

	while(		// current point is still in scene
		0 <= currentPoint.getX() && currentPoint.getX() < (SCENE_WIDTH) &&
		0 <= currentPoint.getY() && currentPoint.getY() < (SCENE_HEIGHT) &&
		0 <= currentPoint.getZ() && currentPoint.getZ() < (SCENE_DEPTH)
		)
	{
		int xCoord = (int)(currentPoint.getX());
		int yCoord = (int)(currentPoint.getY());
		int zCoord = (int)(currentPoint.getZ());

		if(debug_lvl2) cout <<"Checking point (" <<xCoord <<", " <<yCoord <<", " <<zCoord <<")\n";

		if(scene[xCoord][yCoord][zCoord].getShow() == true)		// if you hit a cube
		{
			if(debug_lvl2) cout <<"********** Cube found at (" <<xCoord <<", " <<yCoord <<", " <<zCoord <<")********\n";
			return scene[xCoord][yCoord][zCoord].getColor();
		}
		else		// increment and go again
		{
			currentPoint.incrementX(dX / 50.0);
			currentPoint.incrementY(dY / 50.0);
			currentPoint.incrementZ(1.0 / 50.0);
		}
	}

	if(debug_lvl2) cout <<"didn't hit anything...\n";
	return Color(255, 0, 255);		// return magic pink if ray doesn't hit anything
}

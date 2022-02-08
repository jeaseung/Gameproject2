#include "Wall.h"

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
}

Wall::Wall(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = '*';
}

Wall::~Wall()
{
}

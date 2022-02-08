#include "Goal.h"

Goal::Goal()
{
	X = 0;
	Y = 0;
	Shape = 'G';
	Color.r = 0x00;
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;
}

Goal::Goal(int NewX, int NewY)
{
	/*X = NewX;
	Y = NewY;*/
	Shape = 'G';
	SetActorLocation(NewX, NewY);
	Color.r = 0x00;
	Color.g = 0xff;
	Color.b = 0x00;
	Color.a = 0xff;
}

Goal::~Goal()
{
}



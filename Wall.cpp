#include "Wall.h"
#include "SDL.h"
#include "MyEngine.h"
#include<memory>

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;
	ZOrder = 1;
	bIsBlock = true;
}

Wall::Wall(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;
	ZOrder = 1;
	bIsBlock = true;
}

Wall::~Wall()
{
}

void Wall::Render()
{
	Actor::Render();
}

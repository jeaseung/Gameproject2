#include "Wall.h"
#include "SDL.h"

Wall::Wall()
{
	X = 0;
	Y = 0;
	Shape = '*';
	Color.r = 0x80;
	Color.g = 0x3a;
	Color.b = 0x30;
	Color.a = 0xff;
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
}

Wall::~Wall()
{
}

void Wall::Render(SDL_Renderer* MyRenderer)
{
	Actor::Render(MyRenderer);
}

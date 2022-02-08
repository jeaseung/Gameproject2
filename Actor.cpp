#include "Actor.h"

Actor::Actor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
}

Actor::Actor(int NewX, int NewY)
{
	SetActorLocation(NewX, NewY);
}

Actor::~Actor()
{
	Util::GotoXY(GetX(), GetY());

	std::cout << GetShape() << std::endl;
}

void Actor::Tick()
{
}

void Actor::Render(SDL_Renderer* MyRenderer)
{
	SDL_SetRenderDrawColor(MyRenderer, Color.r, Color.g, Color.b, Color.a);
	SDL_Rect Rect = { GetX() * TileSize,GetY() * TileSize,TileSize,TileSize };

	SDL_RenderFillRect(MyRenderer, &Rect);
	
}

void Actor::BeginPlay()
{
}

inline void Actor::SetActorLocation(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
}

inline void Actor::SetShape(char NewShape)
{
	Shape = NewShape;
}

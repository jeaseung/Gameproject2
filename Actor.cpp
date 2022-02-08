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

void Actor::Render()
{
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

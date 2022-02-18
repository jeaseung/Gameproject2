#include "Actor.h"
#include "MyEngine.h"
#include<memory>
#include "World.h"
#include <iostream>

Actor::Actor()
{
	X = 0;
	Y = 0;
	Shape = ' ';
	bIsBlock = false;
}

Actor::Actor(int NewX, int NewY)
{
	bIsBlock = false;
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
	SDL_SetRenderDrawColor(MyEngine::GetRenderer(), Color.r, Color.g, Color.b, Color.a);
	SDL_Rect Rect = { GetX() * TileSize,GetY() * TileSize,TileSize,TileSize };

	SDL_RenderFillRect(MyEngine::GetRenderer(), &Rect);
	
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

bool Actor::CanMove(int FutureX, int FutureY)
{
	auto ActorList = MyEngine::GetWorld()->GetActorList();

	for (auto CheckActor : ActorList)
	{
		if (CheckActor->GetX() == FutureX && CheckActor->GetY() == FutureY &&
			CheckActor->bIsBlock)
		{
			return false;
		}
	}

	X = FutureX;
	Y = FutureY;

	return true;
}
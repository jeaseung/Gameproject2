#pragma once
#include "SDL.h"
#ifndef __Actor_H__
#define __Actor_H__

#include<iostream>
#include"Util.h"
#include<memory>



class Actor
{
public:
	//오버로딩, 생성자 오버로딩
	Actor();
	Actor(int NewX, int NewY);


	virtual ~Actor();


	virtual void Tick();
	virtual void Render();
	virtual void BeginPlay();

	inline virtual void SetActorLocation(int NewX, int NewY);
	inline virtual void SetShape(char NewShape);
	inline virtual char GetShape() { return Shape; }
	inline virtual int GetX() { return X; }
	inline virtual int GetY() { return Y; }

	bool operator <(Actor& RHS)
	{
		return this->ZOrder > RHS.ZOrder;
	}

	inline static bool Compare(std::shared_ptr<Actor> LHS, std::shared_ptr<Actor>RHS)
	{
		return LHS->ZOrder < RHS->ZOrder;
	}

protected:
	int X;
	int Y;
	char Shape;
	SDL_Color Color;
	int TileSize = 30;

	int ZOrder;



public:
	bool bIsBlock;
	bool CanMove(int FutureX, int FutureY);
};

#endif // __Actor_H__


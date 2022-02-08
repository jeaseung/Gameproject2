#pragma once
#include "SDL.h"
#ifndef __Actor_H__
#define __Actor_H__

#include<iostream>
#include"Util.h"



class Actor
{
public:
	//오버로딩, 생성자 오버로딩
	Actor();
	Actor(int NewX, int NewY);


	virtual ~Actor();


	virtual void Tick(SDL_Event& MyEvent);
	virtual void Render(SDL_Renderer* MyRenderer);
	virtual void BeginPlay();

	inline virtual void SetActorLocation(int NewX, int NewY);
	inline virtual void SetShape(char NewShape);
	inline virtual char GetShape() { return Shape; }
	inline virtual int GetX() { return X; }
	inline virtual int GetY() { return Y; }

protected:
	int X;
	int Y;
	char Shape;
	SDL_Color Color;
	int TileSize = 30;
};

#endif // __Actor_H__


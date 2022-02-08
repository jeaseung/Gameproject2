#pragma once
#ifndef __Actor_H__
#define __Actor_H__

#include<iostream>
#include"Util.h"



class Actor
{
public:
	//�����ε�, ������ �����ε�
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

protected:
	int X;
	int Y;
	char Shape;
};

#endif // __Actor_H__


#pragma once
#ifndef __FLOOR_H__
#define  __FLOOR_H__

#include "Actor.h"
class Floor : public Actor
{
public:
	Floor();
	Floor(int NewX, int NewY);
	virtual ~Floor();
};
#endif // !__FLOOR_H__


#pragma once
#ifndef __PLAYER_H__
#define  __PLAYER_H__


#include "Actor.h"
class Player :public Actor
{
public:
	Player();
	Player(int NewX, int NewY);
	virtual ~Player();
	
};

#endif // !__PLAYER_H__


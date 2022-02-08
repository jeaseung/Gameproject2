#pragma once

#ifndef __PLAYER_H__
#define  __PLAYER_H__

#include"SDL.h"
#include "Actor.h"
class Player :public Actor
{
public:
	Player();
	Player(int NewX, int NewY);
	virtual ~Player();
	
	virtual void Tick(SDL_Event& MyEvent) override;
};

#endif // !__PLAYER_H__


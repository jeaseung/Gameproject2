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
	
	virtual void Tick() override;

	virtual void Render() override;
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	
};

#endif // !__PLAYER_H__


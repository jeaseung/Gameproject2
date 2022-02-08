#pragma once
#ifndef __WALL_H__
#define __WALL_H__

#include "Actor.h"
class Wall : public Actor
{
public:
	Wall();
	Wall(int NewX, int NewY);
	virtual ~Wall();
	virtual void Render(SDL_Renderer* MyRenderer) override;
};

#endif // !__WALL_H__



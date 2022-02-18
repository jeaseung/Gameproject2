#pragma once
#ifndef __ENEMY_H__
#define __ENEMY_H__


#include "Actor.h"
class Enemy : public Actor
{
public:
	Enemy();
	Enemy(int NewX, int NewY);
	virtual ~Enemy();

	virtual void Tick() override;
	
	Uint64 ElapseTime;
	Uint64 ProcessTime;
};

#endif // !__ENEMY_H__
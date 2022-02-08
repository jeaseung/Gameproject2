#pragma once
#ifndef __WORLD_H__
#define __WORLD_H__
#include "Actor.h"
#include "SDL.h"
#include <vector>

class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(class Actor* NewActor);
	void DestoyActor(class Actor* DestroyActor);

	void Tick(SDL_Event& MyEvent);
	void Render(SDL_Renderer* MyRenderer);
	void BeginPlay();

	const std::vector<Actor*>&GetActorList() { return ActorList; }


protected:
	std::vector<class Actor*> ActorList;

};

#endif // !__WORLD_H__


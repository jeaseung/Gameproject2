#pragma once
#ifndef __WORLD_H__
#define __WORLD_H__
#include "Actor.h"
#include "SDL.h"
#include <vector>
#include<memory>

class Actor;

class World
{
public:
	World();
	virtual ~World();

	void SpawnActor(std::shared_ptr< Actor> NewActor);
	void DestoyActor(std::shared_ptr< Actor> DestroyActor);

	void Tick();
	void Render();
	void BeginPlay();

	const std::vector<std::shared_ptr< Actor>>&GetActorList() { return ActorList; }
	Uint64 GetWorldDeltaSeconds() { return DeltaSeconds; };

protected:
	std::vector<std::shared_ptr< Actor>>ActorList;

	Uint64 LastTick;
	Uint64 DeltaSeconds;

};

#endif // !__WORLD_H__


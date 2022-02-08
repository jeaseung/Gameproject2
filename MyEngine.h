#pragma once
#ifndef __MYENGINE_H__
#define __MYENGINE_H__
#include<iostream>
#include<fstream>
#include "World.h"
#include "Goal.h"
#include "Player.h"
#include "Wall.h"


class World;

class MyEngine
{
public:
	MyEngine();
	virtual ~MyEngine();

	void Run();
	void Stop();
	void SpawnActor(Actor* NewActor);
	void DestroyActor(Actor* DstroyActor);
	

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

protected:
	bool bIsRuning = true;
	World* CurrentWorld;
	void BeginPlay();
	void Tick();
	void Rander();
	void Input();


};

#endif // !__MYENGINE_H__


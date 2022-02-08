#pragma once
#ifndef __MYENGINE_H__
#define __MYENGINE_H__
#include<iostream>
#include<fstream>
#include "SDL.h"
#include "World.h"
#include "Goal.h"
#include "Player.h"
#include "Wall.h"


class World;

class MyEngine
{
public:
	//MyEngine();
	MyEngine(std::string Title, std::string LevelName, int Width, int Height);
	virtual ~MyEngine();

	void Init(std::string Title, int Width, int Height);

	void Term();

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
	void Render();
	void Input();
	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;


};

#endif // !__MYENGINE_H__


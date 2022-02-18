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
#include "Enemy.h"

#include<memory>


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

	void SpawnActor(std::shared_ptr< Actor> NewActor);
	void DestroyActor(std::shared_ptr< Actor> DstroyActor);
	

	void LoadLevel(std::string LoadMapName);
	void SaveLevel(std::string SaveMapName);

	inline static SDL_Window* GetWindow() { return MyWindow; }
	inline static SDL_Renderer* GetRenderer() { return MyRenderer; }
	inline static SDL_Event& GetEvent() { return MyEvent; }
	inline static std::unique_ptr<World>& GetWorld() { return CurrentWorld; }
	

protected:
	bool bIsRuning = true;
	static std::unique_ptr<World> CurrentWorld;
	void BeginPlay();
	void Tick();
	void Render();
	void Input();
	static SDL_Window* MyWindow;
	static SDL_Renderer* MyRenderer;
	static SDL_Event MyEvent;


};

#endif // !__MYENGINE_H__


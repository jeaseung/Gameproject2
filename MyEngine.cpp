#include "MyEngine.h"
#include "World.h"
#include <fstream>
#include "Wall.h"
#include "Player.h"
#include "Goal.h"
#include "Floor.h"
#include <iostream>
#include "Enemy.h"


//MyEngine::MyEngine()
//{
//	CurrentWorld = new World();
//
//}

SDL_Window* MyEngine::MyWindow = nullptr;
SDL_Renderer* MyEngine::MyRenderer = nullptr;
SDL_Event MyEngine::MyEvent;
std::unique_ptr<World> MyEngine :: CurrentWorld;

MyEngine::MyEngine(std::string Title, std::string LevelName, int Width, int Height)
{
	CurrentWorld = std::make_unique<World>();
	bIsRuning = true;
	Init(Title, Width, Height);
	LoadLevel(LevelName);

	
}

MyEngine::~MyEngine()
{
	//delete CurrentWorld;
	CurrentWorld = nullptr;
	bIsRuning = false;

	Term();

}

void MyEngine::Init(std::string Title, int Width, int Height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SFL_Init Error : " << SDL_GetError() << std::endl;
		
	}

	MyWindow = SDL_CreateWindow(Title.c_str(), 0, 0,Width, Height, SDL_WINDOW_OPENGL);

	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	if (MyRenderer == nullptr)
	{
		std::cout << "can`t Create renderer :" << SDL_GetError() << std::endl;
	}
}

void MyEngine::Term()
{
	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
}

void MyEngine::Run()
{
	//마우스나 키보드의 이벤트를 설정한다.
	

	bool bIsRunning = true;

	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void MyEngine::Stop()
{
	bIsRuning = false;
}

void MyEngine::SpawnActor(std::shared_ptr< Actor> NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}

void MyEngine::DestroyActor(std::shared_ptr< Actor> DstroyActor)
{
	CurrentWorld->DestoyActor(DstroyActor);
}

void MyEngine::LoadLevel(std::string LoadMapName)
{
	std::ifstream MapFile(LoadMapName);
	int X=0;
	int Y=0;

	while (!MapFile.eof())
	{
		char ReadData = MapFile.get();

		switch (ReadData)
		{
		case '\n':

			Y++;
			X = 0;
			continue;
		case ' ':
			SpawnActor(std::make_shared<Floor>(X, Y));
			break;

		case '*':
			SpawnActor(std::make_shared< Wall> (X, Y));
			SpawnActor(std::make_shared<Floor>(X, Y));
			break;

		case 'P':
			SpawnActor(std::make_shared< Player> (X, Y));
			SpawnActor(std::make_shared<Floor>(X, Y));
			break;

		case 'G':
			SpawnActor(std::make_shared< Goal> (X, Y));
			SpawnActor(std::make_shared<Floor>(X, Y));
			break;
		case 'E':
			SpawnActor(std::make_shared<Enemy>(X, Y));
			SpawnActor(std::make_shared<Floor>(X, Y));
			break;
		}

		X++;
	}

	MapFile.close();
}

void MyEngine::SaveLevel(std::string SaveMapName)
{
	std::ofstream WriteFile(SaveMapName);

	int MaxX = -1;
	int MaxY = -1;

	//std::vector<std::shared_ptr< Actor>> ActorList = CurrentWorld->GetActorList(); 형을 쉽게 알수 있는 것은 auto를 써도 된다. 
	auto ActorList = CurrentWorld->GetActorList();
	for (auto SelectActor : ActorList)
	{
		if (MaxX <= SelectActor->GetX())
		{
			MaxX = SelectActor->GetX();
		}
		if (MaxY <= SelectActor->GetY())
		{
			MaxY = SelectActor->GetY();
		}
	}

	bool bIsWrite = false;

	for (int Y = 0; Y <= MaxY; Y++)
	{
		for (int X = 0; X <= MaxX; X++) 
		{
			for (auto SelectActor : ActorList)
			{
				if (SelectActor->GetX() == X && SelectActor->GetY()==Y)
				{
					WriteFile.put(SelectActor->GetShape());
					bIsWrite=true;
					break;
				}
			}
			if (bIsWrite == false)
			{
				WriteFile.put(' ');
			}
			bIsWrite = false;
		}
		WriteFile.put('\n');
	}

	WriteFile.close();
}

void MyEngine::BeginPlay()
{
	CurrentWorld->BeginPlay();
}

void MyEngine::Tick()
{
	//엔진에서 기본 처리 하는 이벤트
	switch (MyEvent.type)
	{
	case SDL_QUIT:
		bIsRuning = false;
		break;

		//키보드 입력 이벤트
	case SDL_KEYDOWN:
		
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_q:
			bIsRuning = false;
			break;
		}

		break;
	}
	CurrentWorld->Tick();
}

void MyEngine::Render()
{
	SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(MyRenderer);
	//그릴 리스트 준비 
	//PreRender(그릴 준비, 그릴 물체 배치)
	CurrentWorld->Render();

	//GPU가 그린다.
		//Render
	SDL_RenderPresent(MyRenderer);

	
}

void MyEngine::Input()
{
	//Input
	SDL_PollEvent(&MyEvent);



}

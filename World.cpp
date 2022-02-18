#include "World.h"
#include<algorithm>

World::World()
{
}

World::~World()
{
	/*for (int i = 0; i < ActorList.size(); i++)
	{
		delete ActorList[i];
		ActorList[i] = nullptr;
	}*/

	//for (auto iter = ActorList.begin(); iter != ActorList.end(); iter++)
	//{
	//	delete* iter;
	//	*iter = nullptr;
	//}

	for (auto currentActor : ActorList)
	{
		//delete currentActor;
		currentActor = nullptr;
	}

	ActorList.clear();
	
}

void World::SpawnActor(std::shared_ptr< Actor> NewActor)
{
	ActorList.push_back(NewActor);

	sort(ActorList.begin(), ActorList.end(),Actor::Compare);
}

void World::DestoyActor(std::shared_ptr< Actor> DestroyActor)
{
	
	/*for (auto iter = ActorList.begin(); iter != ActorList.end(); iter++)
	{
		if (*iter == DestroyActor) 
		{
			delete* iter;
			*iter = nullptr;
			iter = ActorList.erase(iter);
			break;
		}
	}*/

	ActorList.erase(find(ActorList.begin(), ActorList.end(), DestroyActor));

	//delete DestroyActor;
	DestroyActor = nullptr;

}

void World::Tick()
{
	DeltaSeconds = SDL_GetTicks64() - LastTick;
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Tick();
	}
}

void World::Render()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->Render();
	}

	LastTick = SDL_GetTicks64();
}


void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}

#include "World.h"

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
		delete currentActor;
		currentActor = nullptr;
	}

	ActorList.clear();
	
}

void World::SpawnActor(Actor* NewActor)
{
	ActorList.push_back(NewActor);
}

void World::DestoyActor(Actor* DestroyActor)
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

	delete DestroyActor;
	DestroyActor = nullptr;

}

void World::Tick()
{
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
}

void World::Input()
{
}

void World::BeginPlay()
{
	for (auto SelectedActor : ActorList)
	{
		SelectedActor->BeginPlay();
	}
}

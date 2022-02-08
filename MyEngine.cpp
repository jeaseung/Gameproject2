#include "MyEngine.h"

MyEngine::MyEngine()
{
	CurrentWorld = new World();

}

MyEngine::~MyEngine()
{
	delete CurrentWorld;
	CurrentWorld = nullptr;
	bIsRuning = false;

}

void MyEngine::Run()
{
	void BeginPlay();
	while (bIsRuning)
	{
		
		void Input();
		void Tick();
		void Rander();
		
	}
}

void MyEngine::Stop()
{
	bIsRuning = false;
}

void MyEngine::SpawnActor(Actor* NewActor)
{
	CurrentWorld->SpawnActor(NewActor);
}

void MyEngine::DestroyActor(Actor* DstroyActor)
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

		case '*':
			SpawnActor(new Wall(X, Y));
			break;

		case 'P':
			SpawnActor(new Player(X, Y));
			break;
		case 'G':
			SpawnActor(new Goal(X, Y));
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

	std::vector<Actor*> ActorList = CurrentWorld->GetActorList();

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

	for (int Y = 0; Y < MaxY; Y++)
	{
		for (int X = 0; X < MaxX; X++) 
		{
			for (auto SelectActor : ActorList)
			{
				if (SelectActor->GetX() == X && SelectActor->GetY())
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
	CurrentWorld->Tick();
}

void MyEngine::Rander()
{
	CurrentWorld->Render();
}

void MyEngine::Input()
{
	CurrentWorld->Input();
}

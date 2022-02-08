#include <iostream>
#include <vector>
#include "MyEngine.h"
#include "SDL.h"


#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


using namespace std;


int SDL_main(int argc, char* argv[])
{
	MyEngine* PlayEngine = new MyEngine("MazeGame","Level01.Map",800,600);
	PlayEngine->Run();

	delete PlayEngine;
	PlayEngine = nullptr;


	return 0;
}
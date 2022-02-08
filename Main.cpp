#include <iostream>
#include <vector>
#include "SDL.h"


#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


using namespace std;


int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SFL_Init Error : "  << SDL_GetError() << endl;
		return -1;
	}

	SDL_Window* MyWindow = SDL_CreateWindow("First SDL Example", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	//마우스나 키보드의 이벤트를 설정 한다.
	SDL_Event MyEvent;

	bool bIsRunning = true;

	while (bIsRunning)
	{
		SDL_PollEvent(&MyEvent);

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;

			//키보드 입력 이벤트
		case SDL_KEYDOWN:
			cout << SDL_GetKeyName(MyEvent.key.keysym.sym) <<"키 눌러짐" << endl;
			break;

		case SDL_MOUSEBUTTONDOWN:
			cout <<(MyEvent.button.button==SDL_BUTTON_LEFT)<< "마우스 눌림" << endl;
			cout <<"("<<MyEvent.button.x << "," << MyEvent.button.y << ")" << endl;
			break;
		}
		

	}

	SDL_Delay(10000);

	SDL_DestroyWindow(MyWindow);
	SDL_Quit();

	return 0;
}
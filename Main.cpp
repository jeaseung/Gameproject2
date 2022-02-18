#include <iostream>
#include <vector>
#include "MyEngine.h"
#include "SDL.h"
#include<algorithm>
#include<vector>
#include <memory>
#include "Actor.h"


#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

class Test
{
public:
	Test(int NewNumber) { Number = NewNumber; }
	int Number = 0;

	//연산자 오버로딩, operator overloding
	//Test[1]>Test[2]
	bool operator <(Test& RHS)
	{
		return this -> Number > RHS.Number;
	}
	
};

#include "Floor.h"
#include "Wall.h"
#include "Player.h"
#include "Goal.h"

int SDL_main(int argc, char* argv[])
{
	unique_ptr<MyEngine> PlayEngine = make_unique<MyEngine>("Maze Game", "Level01.map", 800, 600);

	PlayEngine->Run();

	PlayEngine = nullptr;

	/*vector<Test> TestList;
	TestList.push_back(Test(9));
	TestList.push_back(Test(4));
	TestList.push_back(Test(1));
	TestList.push_back(Test(2));
	TestList.push_back(Test(3));
	TestList.push_back(Test(6));
	TestList.push_back(Test(5));
	TestList.push_back(Test(8));
	TestList.push_back(Test(0));
	TestList.push_back(Test(7));

	TestList[1] < TestList[2];
	
	sort(TestList.begin(),TestList.end());

	for (auto Object : TestList)
	{
		cout << Object.Number << endl;
	}*/

	

	return 0;
}
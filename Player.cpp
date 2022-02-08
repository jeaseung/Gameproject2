#include "Player.h"

Player::Player()
{
	X = 0;
	Y = 0;
	Shape = 'P';
	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;
}

Player::Player(int NewX, int NewY)
{
	X = NewX;
	Y = NewY;
	Shape = 'P';

	Color.r = 0xff;
	Color.g = 0x00;
	Color.b = 0x00;
	Color.a = 0xff;

}

Player::~Player()
{
}

void Player::Tick(SDL_Event& MyEvent)
{
	if (MyEvent.type == SDL_KEYDOWN)
	{
		switch (MyEvent.key.keysym.sym)
		{
		case SDLK_LEFT:
			X--;
			break;
		case SDLK_RIGHT:
			X++;
			break;
		case SDLK_UP:
			Y--;
			break;
		case SDLK_DOWN:
			Y++;
			break;

		}
	}
}


#include "Game.h"

void Game::HandleEvents(SDL_Event * event)
{
	switch(event->type)
	{
		case SDL_QUIT: Quit(); break;
	}
}

void Game::Quit()
{
	gameIsRunning = false;
}
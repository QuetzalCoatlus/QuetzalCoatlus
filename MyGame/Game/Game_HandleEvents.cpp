#include "Game.h"

void Game::HandleEvents(SDL_Event * event)
{
	switch(event->type)
	{
		case SDL_QUIT: Quit(); break;
        default: PlayerInput::HandleEvents(event);
	}
}

void Game::Quit()
{
	gameIsRunning = false;
}
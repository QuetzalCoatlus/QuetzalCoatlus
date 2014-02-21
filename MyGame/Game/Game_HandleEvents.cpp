#include "Game.h"

void Game::HandleEvents(SDL_Event * event)
{
	switch(event->type)
	{
		case SDL_QUIT: Quit(); break;
        case SDL_KEYDOWN:
        {
            KeyDown(event->key.keysym.sym);
            break;
        }
        case SDL_KEYUP:
        {
            KeyUp(event->key.keysym.sym);
            break;
        }
	}
}

void Game::Quit()
{
	gameIsRunning = false;
}

void Game::KeyDown(SDL_Keycode code)
{
    switch(code)
    {
        case SDLK_UP:
            gameEntity->isMovingUp = true;
            break;
        case SDLK_DOWN:
            gameEntity->isMovingDown = true;
            break;
        case SDLK_LEFT:
        {
            gameEntity->isMovingLeft = true;
            gameEntity->isFacingLeft = true;
            gameEntity->isFacingRight = false;
            break;
        }
        case SDLK_RIGHT:
        {
            gameEntity->isMovingRight = true;
            gameEntity->isFacingRight = true;
            gameEntity->isFacingLeft = false;
            break;
        }
    }
}

void Game::KeyUp(SDL_Keycode code)
{
    switch(code)
    {
        case SDLK_UP:
            gameEntity->isMovingUp = false;
            break;
        case SDLK_DOWN:
            gameEntity->isMovingDown = false;
            break;
        case SDLK_LEFT:
            gameEntity->isMovingLeft = false;
            break;
        case SDLK_RIGHT:
            gameEntity->isMovingRight = false;
            break;
    }
}
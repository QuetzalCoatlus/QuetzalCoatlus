#include "Game.h"

void Game::Render()
{
	ClearScreen();
	UpdateScreen();
}

void Game::ClearScreen()
{
	SDL_RenderClear(gameRenderer);
}

void Game::UpdateScreen()
{
	SDL_RenderPresent(gameRenderer);
}
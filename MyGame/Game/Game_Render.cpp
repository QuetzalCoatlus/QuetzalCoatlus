#include "Game.h"

void Game::Render()
{
	ClearScreen();
    DisplayTextures();
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

void Game::DisplayTextures()
{
    gameEntity->Render(gameRenderer);
}
#include "Game.h"

void Game::Cleanup()
{
	DestroyWindow();
	QuitSdlSubSystems();
}

void Game::DestroyWindow()
{
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameWindow=NULL;
	gameRenderer=NULL;
}

void Game::QuitSdlSubSystems()
{
	IMG_Quit();
	SDL_Quit();
}
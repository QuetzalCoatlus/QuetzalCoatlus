#include "Game.h"

void Game::Cleanup()
{
	DestroyWindow();
    DestroyTextures();
	QuitSdlSubSystems();
}

void Game::DestroyWindow()
{
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameWindow=NULL;
	gameRenderer=NULL;
}

void Game::DestroyTextures()
{
    gameTexture->DestroyTexture();
    gameTexture=NULL;
}

void Game::QuitSdlSubSystems()
{
	IMG_Quit();
	SDL_Quit();
}
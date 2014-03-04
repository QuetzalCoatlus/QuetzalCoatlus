#include "Game.h"
#include <iostream>

bool Game::InitializeGame()
{
		bool successfullyInitializedSDL = InitializeSDL();
		if(!successfullyInitializedSDL)
			return false;
    
		bool successfullyCreatedWindow = CreateWindow();
		if (!successfullyCreatedWindow)
			return false;
    
		bool successfullyCreatedRenderer = CreateRenderer();
		if (!successfullyCreatedRenderer)
			return false;
    
		bool successfullyInitImgLoading= InitializeImageLoading();
		if (!successfullyInitImgLoading)
			return false;
    
        PlayerInput::Initialize();
    
		return true;
}

bool Game::InitializeSDL()
{
	return SDL_Init(SDL_INIT_VIDEO) >= 0;
}

bool Game::CreateWindow()
{
	gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		 				WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	return gameWindow != NULL;	
}

bool Game::CreateRenderer()
{
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
	InitializeRendererColor();
    
	return gameRenderer != NULL; 
}

void Game::InitializeRendererColor()
{
	SDL_SetRenderDrawColor(gameRenderer, 0x00, 0xFF, 0xEF, 0xFF);
}

bool Game::InitializeImageLoading()
{
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
	
	return ((IMG_Init(imgFlags) & imgFlags) != 0);
}

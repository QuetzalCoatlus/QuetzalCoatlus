#include <Game.h>

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
		
		bool successfullyInitImgLoading= IntializeImageLoading();
		if (!successfullyInitImgLoading)
			return false;
		
		return true;
}

private bool InitializeSDL()
{
	return SDL_Init(SDL_INIT_VIDEO) > 0;
}

private bool CreateWindow()
{
	gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		 				WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	return gWindow != NULL;	
}

private bool CreateRenderer()
{
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	
	return gRenderer != NULL; 
}

private void IntializeRendererColor()
{
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
}

private void InitializeImageLoading()
{
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPEG;
	
	return IMG_Init(imgFlags) & imgFlags;
}
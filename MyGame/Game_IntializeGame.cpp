#include <Game.h>

bool Game::InitializeGame()
{
		bool successfullyInitializedSDL = InitializeSDL();
		
		if(!successfullyInitializedSDL)
			return false;
}

private bool InitializeSDL()
{
	return SDL_Init(SDL_INIT_VIDEO) > 0;
}
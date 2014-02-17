#include "Game.h"

Game::Game()
{
	gameWindow=NULL;
	gameRenderer=NULL;
	gameTexture=NULL;
	
	gameIsRunning=true;
}

int Game::ExecuteGame()
{
	bool successfullyInitializedGame = InitializeGame();
	
	if (!successfullyInitializedGame)
		return 1;
	
	bool successfullyLoadedAssets = LoadAssets();
	
	if (!successfullyLoadedAssets)
		return 1;
		
	SDL_Event event;
		
	RunGameLoop(&event);
}

void Game::RunGameLoop(SDL_Event * event)
{
	while(gameIsRunning)
	{
		RunEventLoop(event);
		
		Update();
		Render();
	}
}

void Game::RunEventLoop(SDL_Event * event)
{
	while(SDL_PollEvent(event))
	{
		HandleEvents();
	}
}

int main(int argc, char * argv[])
{
	Game theGame;
	return theGame.ExecuteGame();
}

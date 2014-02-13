#include <Game.h>

void Game::Cleanup()
{
	DestroyWindow();
	QuitSdlSubsystems();
}

private void DestroyWindow()
{
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gWindow=NULL;
	gRenderer=NULL;
}

private void QuitSdlSubSystems()
{
	IMG_Quit();
	SDL_Quit();
}
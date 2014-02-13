#include <Game.h>

void Game::Render()
{
	ClearScreen();
	UpdateScreen();
}

private void ClearScreen()
{
	SDL_RenderClear(gameRenderer);
}

private void UpdateScreen()
{
	SDL_RenderPresent(gameRenderer);
}
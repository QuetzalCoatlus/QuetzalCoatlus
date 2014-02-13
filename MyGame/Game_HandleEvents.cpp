#include <Game.h>

void Game::HandleEvents(SDL_Event * event)
{
	switch(event.Type)
	{
		case SDL_Quit: Quit(); break;
	}
}

private void Quit()
{
	gameIsRunning = false;
}
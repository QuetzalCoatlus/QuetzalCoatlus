#include "Game.h"

void Game::Update()
{
    GameFps::FpsControl.Update();
    gameEntity->Update();
}

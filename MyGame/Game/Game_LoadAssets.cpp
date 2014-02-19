#include "Game.h"

bool Game::LoadAssets()
{
    gameAnimation->SetMaxFramesInAnimation(6);

	return gameTexture->LoadTextureFromFile("/Users/fantasyzone/Documents/C:C++ Programming/QuetzalCoatlus/QuetzalCoatlus/WalkCycle.png", gameRenderer);
}

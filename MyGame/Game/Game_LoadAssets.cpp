#include "Game.h"

bool Game::LoadAssets()
{
	return gameTexture->LoadTextureFromFile("/Users/fantasyzone/Documents/C:C++ Programming/QuetzalCoatlus/QuetzalCoatlus/test_image.jpg", gameRenderer);
}

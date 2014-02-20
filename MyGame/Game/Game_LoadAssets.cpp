#include "Game.h"

bool Game::LoadAssets()
{
    SDL_Rect * entityBoundingBox = new SDL_Rect
    {
      0,
      0,
      64,
      73
    };
    gameEntity = new GameEntity(0,0);
    gameEntity->Load("/Users/fantasyzone/Documents/C:C++ Programming/QuetzalCoatlus/QuetzalCoatlus/WalkCycle.png", gameRenderer);
    return true;
}

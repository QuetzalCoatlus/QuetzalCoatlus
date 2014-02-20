#include "GameFps.h"

GameFps GameFps::FpsControl;

GameFps::GameFps()
{
    oldTime = 0;
    lastTime = 0;
    numberOfFrames = 0;
    framesThisSecond = 0;

    speedFactor = 0.0f;
}

void GameFps::Update()
{
    if (oldTime + ONE_SECOND < SDL_GetTicks())
    {
        oldTime = SDL_GetTicks();
        numberOfFrames = framesThisSecond;
        framesThisSecond = 0;
    }
    
    speedFactor = ((SDL_GetTicks() - lastTime) / ((float)ONE_SECOND)) * MOVEMENT_RATE;
    
    lastTime = SDL_GetTicks();
    
    framesThisSecond++;
}

int GameFps::GetFps()
{
    return numberOfFrames;
}

float GameFps::GetSpeedFactor()
{
    return speedFactor;
}
#include "GameAnimation.h"
#include <iostream>

GameAnimation::GameAnimation()
{
    currentFrame=0;
    maxFrames=0;
    timeAtLastCycle=0;
    
    framesIncremented=1;
    frameRate=90;
}

void GameAnimation::Animate()
{
    if(timeAtLastCycle + frameRate > SDL_GetTicks())
        return;
    
    timeAtLastCycle = SDL_GetTicks();
    
    currentFrame += framesIncremented;
    
    if(currentFrame >= maxFrames)
        currentFrame = 0;
}

void GameAnimation::SetFrameRate(int frameRate)
{
    this->frameRate = frameRate;
}

int GameAnimation::GetFrameRate()
{
    return frameRate;
}

void GameAnimation::SetCurrentFrame(int currentFrame)
{
    this->currentFrame = currentFrame;
}

int GameAnimation::GetCurrentFrame()
{
    return currentFrame;
}

void GameAnimation::SetMaxFramesInAnimation(int maxFrames)
{
    this->maxFrames = maxFrames;
}

int GameAnimation::GetMaxFramesInAnimation()
{
    return maxFrames;
}

#include "GameEntity.h"
#include <iostream>

GameEntity::GameEntity(int x, int y) : Entity(x,y)
{
    entityTexture = new GameTexture();
    entityAnimation = new GameAnimation();
    xVelocity = 2.0f;
    yVelocity = 2.0f;
    
    isMovingLeft = false;
    isMovingDown = false;
    isMovingRight = false;
    isMovingUp = false;
    isFacingRight = true;
    
    currentFrameState = 0;
}

bool GameEntity::Load(std::string filename, SDL_Renderer *gameRenderer)
{
    entityAnimation->SetMaxFramesInAnimation(6);

	return entityTexture->LoadTextureFromFile(filename, gameRenderer);
}

void GameEntity::Update()
{
    bool isNotMoving = !isMovingDown &&
    !isMovingUp && !isMovingLeft && !isMovingRight;

    if(isMovingLeft)
        currentFrameState = 3;
    else if(isMovingRight)
        currentFrameState = 2;
    else if(isFacingLeft && isNotMoving)
        currentFrameState = 1;
    else if(isFacingRight&& isNotMoving)
        currentFrameState = 0;
    else if((isMovingUp && isFacingLeft) || (isMovingDown && isFacingLeft))
        currentFrameState = 3;
    else if ((isMovingDown && isFacingRight) ||
        (isMovingUp && isFacingRight))
        currentFrameState = 2;
    
    
    
    entityAnimation->Animate();
    
    Move();
}

void GameEntity::Render(SDL_Renderer * gameRenderer)
{
       SDL_Rect clip =
    {
        currentFrameState * 64,
        entityAnimation->GetCurrentFrame()*73,
        64,
        73
    };
        
    entityTexture->RenderTexture(xPosition,yPosition, gameRenderer,&clip);
}

void GameEntity::Destroy()
{
    entityTexture->DestroyTexture();
}

void GameEntity::Move()
{
    float xDisplacement = 0.0f;
    float yDisplacement = 0.0f;
    
    if(isMovingLeft)
        xDisplacement -= GameFps::FpsControl.GetSpeedFactor() * xVelocity;
    else if(isMovingRight)
        xDisplacement +=  GameFps::FpsControl.GetSpeedFactor() * xVelocity;
    if(isMovingUp)
        yDisplacement -=  GameFps::FpsControl.GetSpeedFactor() * yVelocity;
    else if(isMovingDown)
        yDisplacement +=  GameFps::FpsControl.GetSpeedFactor() * yVelocity;
    
    IncrementalMove(xDisplacement,yDisplacement);
}

void GameEntity::IncrementalMove(float xDisplacement, float yDisplacement)
{
    double incrementalDisplacementX = 0;
    double incrementalDisplacementY = 0;
    
    if(xDisplacement == 0 && yDisplacement == 0)
        return;
    
    if(xDisplacement > 0)
        incrementalDisplacementX = GameFps::FpsControl.GetSpeedFactor();
    else if (xDisplacement < 0)
        incrementalDisplacementX = -GameFps::FpsControl.GetSpeedFactor();
    
    if(yDisplacement > 0)
        incrementalDisplacementY = GameFps::FpsControl.GetSpeedFactor();
    else if (yDisplacement < 0)
        incrementalDisplacementY = -GameFps::FpsControl.GetSpeedFactor();
    
    xPosition +=xDisplacement;
    yPosition +=yDisplacement;
}

void GameEntity::HandleCollision()
{

}